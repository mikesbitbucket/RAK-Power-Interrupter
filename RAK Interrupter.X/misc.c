/* ************************************************************************** */
/** Misc Functions

  @Company
    SupraTech

  @File Name
    misc.c

  @Summary
    Misc functions - timers, etc.

  @Description
    Various button handling functions
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

#include "mcc_generated_files/system/system.h"
#include "misc.h"
#include "global_defs.h"
#include <math.h>  // for division...



/* ************************************************************************** */
/* ************************************************************************** */
/* Section: File Scope or Global Data                                         */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */
/** Descriptive Data Item Name

  @Summary
    Brief one-line summary of the data item.
    
  @Description
    Full description, explaining the purpose and usage of data item.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
    
  @Remarks
    Any additional remarks
 */
static uint16_t SysTick = 0;
static uint16_t Heartbeat_tmr = 0;
static uint8_t LED_Heartbeat_tmr = 0, A2D_tmr = 0;
static uint24_t LoRa_tmr = 0; // This gives us max of 46 hours with 10ms tic for timeout
static uint24_t LoRa_Timeout = LORA_DEFAULT_TIMEOUT;
static uint16_t SupplyVoltage = 0;  // This is the VCC voltage in mV - Rem - it is through a Schottky diode

static uint16_t A2D_Array[3]; // stores the latest A2D readings for the current monitor and Supply Voltage
static uint16_t Power_tmr;

uint32_t Average5VCurrent = 0, AverageBatCurrent = 0;  // Long term averages of the current monitors

enum A2D_States {
    READ_5V = 0,
    READ_BAT = 1,
    READ_SUPPLY = 2,
};
static uint8_t A2D_State = 0;  // What channel are we reading

/* ************************************************************************** */
/* ************************************************************************** */
// Section: Local Functions                                                   */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */

/* ************************************************************************** */

/** 
  @Function
    int ExampleLocalFunctionName ( int param1, int param2 ) 

  @Summary
    Brief one-line description of the function.

  @Description
    Full description, explaining the purpose and usage of the function.
    <p>
    Additional description in consecutive paragraphs separated by HTML 
    paragraph breaks, as necessary.
    <p>
    Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.

  @Precondition
    List and describe any required preconditions. If there are no preconditions,
    enter "None."

  @Parameters
    @param param1 Describe the first parameter to the function.
    
    @param param2 Describe the second parameter to the function.

  @Returns
    List (if feasible) and describe the return values of the function.
    <ul>
      <li>1   Indicates an error occurred
      <li>0   Indicates an error did not occur
    </ul>

  @Remarks
    Describe any special behavior not described above.
    <p>
    Any additional remarks.

  @Example
    @code
    if(ExampleFunctionName(1, 2) == 0)
    {
        return 3;
    }
 */
//static int ExampleLocalFunction(int param1, int param2) {
//    return 0;
//}








/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

/*  A brief description of a section can be given directly below the section
    banner.
 */


// *****************************************************************************

/** 
  @Function
    IncSysTick 

  @Summary
 Increments the System Tic - this gets called from the Timer overflow interrupt
 * every 10ms

  @Remarks
 In SysTic
 */
void IncSysTick(void)
{
    SysTick++;
    LoRa_tmr++;
}

/** 
  @Function
    ClearSysTick 

  @Summary
 Clears the System Tic

  @Remarks
 Clear SysTic
 */
void ClearSysTick(void)
{
    SysTick = 0;
}

// *****************************************************************************

/** 
  @Function
    GetSysTick 

  @Summary
    Gets the current SysTick

  @Remarks
    Get and return current SysTick
 */
uint16_t GetSysTick(void)
{
    uint16_t retval;

    PIE3bits.TMR1IE = 0; // Shut off interrupt
    retval = SysTick;
    PIE3bits.TMR1IE = 1; // turn on interrupt
    return retval;
}

// *****************************************************************************

/** 
  @Function
    DoHeartBeat 

  @Summary
 * Does any heartbeat related tasks - blink LED, etc

  @Remarks
 *  Heartbeat Stuff
 */

void DoHeartBeat()
{
    // Heartbeat check
    if(GetSysTick() != Heartbeat_tmr)  // this is simpler with 1 tick per heartbeat - Timer 0 is set to 10 ms
    {
        Heartbeat_tmr = GetSysTick(); // get new time val
        // do the LED heartbeat check
        LED_Heartbeat_tmr++;
        if(LED_Heartbeat_tmr >= LED_HEARTBEAT_INTERVAL)
        {
            GRNLED_Toggle(); // Toggle Heartbeat light
            LED_Heartbeat_tmr = 0;
            
            // Add some stuff to check the dip switches and set stuff accordingly - only needs t be done once in while
            
            
            // Update the DAC Threshold
            SetNew5VDACThreshold();
        }
        
        // See if we want to do a new A2D
        A2D_tmr++;
        if(A2D_tmr >= A2D_UPDATE_INTERVAL)
        {
            // lets kick off another reading
            A2D_tmr = 0;  // reset the timer
            DoA2D();
        }
        
        if(LoRa_tmr > LoRa_Timeout)
        {
            // we have exceed the time for a current pulse that would be a LoRa transmission, pull the plug
            PullThePlug();
        }
    }  // End if
}  // End Heartbeat


// *****************************************************************************

/** 
  @Function
    DoA2D 

  @Summary
 * Periodically reads the A2D for each channel

  @Remarks
 *  A2D stuff
 * 
 * Shares the state with the Interrupt handler
 */

void DoA2D()
{
    // If time is up, set a channel and start another conversion
    // Note - State will get changed in the A2D Interrupt handler
    switch (A2D_State)
            
    {
        case READ_5V:
            ADC_SelectContext(0);  // Use FVR for Ref, select channel
            ADC_StartConversionOnChannel(MON5V);  // Read the 5v Current Monitor Input
            break;
            
        case READ_BAT:
            ADC_SelectContext(0);  // Use FVR for Ref, select channel
            ADC_StartConversionOnChannel(BATMON); // Read the Battery Current Monitor Input
            break;
            
        case READ_SUPPLY:
            ADC_SelectContext(1);  // Use VDD for Ref, Read FVR
            // Note - because context sets up the right channel, probably could just kick off the convertion!
            // Don't need the call with the channel select, but makes it easier to read.
            ADC_StartConversionOnChannel(channel_FVR_Buffer1);  // Read the Ref (2.048 using the supply as the Vref+)
            SupplyVoltage = GetSupplyVoltage();
            break;
            
        default:
            A2D_State = READ_5V;
            break;
    }  // End Switch
}

// *****************************************************************************

/** 
  @Function
    A2DIntHandler 

  @Summary
 * Handles the A2D readings for input from current monitors and supply voltage
 * measuring

  @Remarks
 *  A2D Interrupt handler
 *  Shares the state with the Interrupt handler
 */

void A2DIntHandler(void)
{
    // every interrupt, put in a new A2D reading
    switch (A2D_State)
    {
        case READ_5V:
            // stuff the reading in the array
            A2D_Array[READ_5V] = ADC_GetConversionResult();
            DoLongTermAverage5v(A2D_Array[READ_5V]);  // Send current result to long term averager..
            A2D_State = READ_BAT; // Move to next state so next conversion is next channel
            break;
            
        case READ_BAT:
            // stuff the reading in the array
            A2D_Array[READ_BAT] = ADC_GetConversionResult();
            A2D_State = READ_SUPPLY; // Move to next state so next conversion is next channel
            break;   
            
        case READ_SUPPLY:
            // stuff the reading in the array
            A2D_Array[READ_SUPPLY] = ADC_GetConversionResult();
            A2D_State = READ_5V; // Move to next state so next conversion is next channel
            break;
            
        default:
            // Do nothing, just reset state
            A2D_State = READ_5V; // Nove to next state
            break;
    }
    
}

// *****************************************************************************

/** 
  @Function
    GetSupplyVoltage 

  @Summary
 * Periodically reads the A2D for each channel

  @Remarks
 *  Function to return supply voltage - assumes the A2D function above has stuffed
 * the right values in the variable that holds supply voltage
 */

uint16_t GetSupplyVoltage(void)
{
    // Return the Supply voltage in mV - e.g. 5023 = 5.023v
    //  ***  Note   *** this takes about 1000 Fcyc or about 62uS @ 64Mhz to run a dividion! 
    // Don't call this too often
     return (uint16_t)(8386560 / A2D_Array[2]);
    
}

// *****************************************************************************

/** 
  @Function
    Pretty Self explanatory functions for turning power on and off from each 
 * supply - 5v and battery 

  @Summary
 * Periodically reads the A2D for each channel

  @Remarks
 *  Function to return supply voltage - assumes the A2D function above has stuffed
 * the right values in the variable that holds supply voltage
 */

void TurnOn5v(void)
{
    CONTROL5V_SetHigh();
}

void TurnOff5v(void)
{
    CONTROL5V_SetLow();
}

void TurnOnBat(void)
{
    CONTROLBAT_SetHigh();
}

void TurnOffBat(void)
{
    CONTROLBAT_SetLow();
}


// *****************************************************************************

/** 
  @Function
    DoLongTermAverage5v 

  @Summary
 * Does a running long term average of the 5V current line

  @Remarks
 *  Long term average of the 5v current monitor line
 * Using 32 bit numbers - upper 16 bits are the 'integer' part, the lower 16 are the fractional part
 * Doing this to speed up math and not use floating point
 * Idea is to take current reading and difference it to long term average, and then add/subtract a little bit of the
 * difference back to the long term average. Should simulate a simple RC filter.
 */
void DoLongTermAverage5v(uint16_t currentA2D)
{
    uint32_t ShiftedCurrentA2D;
    
    ShiftedCurrentA2D = (uint32_t)(currentA2D) << 16;  // Move to upper bits.
    
    if(ShiftedCurrentA2D >= Average5VCurrent)
    {
        // We are above - so add to current. Doing with this to avoid signed math
        ShiftedCurrentA2D = ShiftedCurrentA2D - Average5VCurrent;  // This is now the difference
        ShiftedCurrentA2D = ShiftedCurrentA2D >> AVERAGER_TIME_CONSTANT; // This now a fraction of the original difference
        Average5VCurrent += ShiftedCurrentA2D;  // add this to the running total
    }
    else
    {
        // We are below - so subtract from current. Doing with this to avoid signed math
        ShiftedCurrentA2D = Average5VCurrent - ShiftedCurrentA2D;  // This is now the difference
        ShiftedCurrentA2D = ShiftedCurrentA2D >> AVERAGER_TIME_CONSTANT; // This now a fraction of the original difference
        Average5VCurrent -= ShiftedCurrentA2D;  // subtract this from the running total
    }
}


// *****************************************************************************
/** 
  @Function
    SetNew5VDACThreshold 

  @Summary
 * Sets a new 8 bit DAC threshold based on the current long term average + some delta

  @Remarks
 *  The amount over the long term average to set the DAC trip threshold will depend on the
 * dip switch settings
 */
void SetNew5VDACThreshold(void)
{
    DAC2_SetOutput( (uint8_t)(Average5VCurrent >>20) + 50);  // we need to make this dependant on switch and some other algorithm
}

// *****************************************************************************

/** 
  @Function
    PetTheDog 

  @Summary
 * Hits the Watch Dog Timer to reset it

  @Remarks
 *  Resets the WatchDog Timer
 */
void PetTheDog(void)
{
    CLRWDT();
}


// *****************************************************************************

/** 
  @Function
    CheckCurrentMonitors 

  @Summary
 * Checks the Current Monitor inputs, and resets the timer if any are above threshold

  @Remarks
 *  Check Monitors - reset timer if tripped
 */
void CheckCurrentMonitors(void)
{
    if((CMP1_GetOutputStatus() == 1) || (CMP2_GetOutputStatus() == 1))
    {
        // Got a LoRa xmission
        ResetLoRaTimer();
        REDLED_SetHigh();
    }
    else
    {
        REDLED_SetLow();
    }
}

void ResetLoRaTimer(void)
{
    LoRa_tmr = 0;
}

void PullThePlug(void)
{
    //uint16_t killme;
    // pulls power and waits
    TurnOff5v();
    TurnOffBat();
    Power_tmr = GetSysTick();
    //killme = (uint16_t)(GetSysTick() - Power_tmr);
    REDLED_SetHigh(); // Show we are rebooting
    GRNLED_SetLow();  // turn off the Green LED  so we can easily see we are screwed
    while((uint16_t)(GetSysTick() - Power_tmr) < LORA_POWER_OFF_TIME) continue; // wait here for the off time
    REDLED_SetLow(); // Turn off the Red LED
    TurnOn5v();
    TurnOnBat();
    ResetLoRaTimer();
    // Maybe set the Red LED high for 24 hours to show there was a reset??
}


/* *****************************************************************************
 End of File
 */

