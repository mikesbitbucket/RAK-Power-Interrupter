 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
 * 
 * 
 * RAK Power Supply Interrupter
*/
#include "mcc_generated_files/system/system.h"
#include "misc.h"
#include "global_defs.h"


uint16_t SupplyVoltage;
uint8_t i,j;
uint16_t delay;


/*
    Main application
*/

int main(void)
{
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts 
    // Use the following macros to: 

    // Enable the Global High Interrupts 
    INTERRUPT_GlobalInterruptHighEnable(); 

    // Disable the Global High Interrupts 
    //INTERRUPT_GlobalInterruptHighDisable(); 

    // Enable the Global Low Interrupts 
    INTERRUPT_GlobalInterruptLowEnable(); 

    // Disable the Global Low Interrupts 
    //INTERRUPT_GlobalInterruptLowDisable(); 
    
    
    Timer1_Initialize();  // Need to do this again otherwise strange results on reset....
    Timer1_OverflowCallbackRegister(IncSysTick); // Set the Timer Int Callback
    ADC_SetADIInterruptHandler(A2DIntHandler);  // Set the callback for A2D interrupt

    // Start the Sys Timer
    Timer1_Start();
    
    //DAC2_SetOutput(0);
    
    // Wiggle the LEDs
    for(i = 0; i <10; i++)
    {
        GRNLED_SetHigh();
        REDLED_SetLow();
        //__delay_ms(100);
        while(GetSysTick() <= 10) continue;
        ClearSysTick();
        //for(delay=0; delay < 40000; delay++) continue;
        GRNLED_SetLow();
        REDLED_SetHigh();
        //__delay_ms(100);
//        DAC2_SetOutput(DAC2_GetOutput() + 32);
        while(GetSysTick() <= 10) continue;
//        DAC2_SetOutput(DAC2_GetOutput() +32);
        ClearSysTick();
    }
    REDLED_SetLow();
    ClearSysTick();
            
    // Turn on the supplies
    TurnOn5v();
    TurnOnBat();
    
    // We may want to wait a few ms for power to come up, and then get current
    // states, voltages, etc.
    
    //__delay_ms(30);
    
    SWDTEN = 1; // Start the Watch Dog Timer

    DAC2_SetOutput(100);  // Set initial levels of the DACs
    DAC3_SetOutput(100);
            
            
    while(1)
    {
        DoHeartBeat(); // Do all the hearbeat related stuff
        CheckCurrentMonitors(); // See if we are transmitting
        
        // Need to add:
        // Tracking of current levels to set the threshold on the DACs
        
        PetTheDog();  // Clear the Watch Dog Timer
    }    
}