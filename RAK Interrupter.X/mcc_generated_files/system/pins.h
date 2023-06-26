/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.0
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
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 aliases
#define MON5V_TRIS                 TRISAbits.TRISA0
#define MON5V_LAT                  LATAbits.LATA0
#define MON5V_PORT                 PORTAbits.RA0
#define MON5V_WPU                  WPUAbits.WPUA0
#define MON5V_OD                   ODCONAbits.ODCA0
#define MON5V_ANS                  ANSELAbits.ANSELA0
#define MON5V_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define MON5V_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define MON5V_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define MON5V_GetValue()           PORTAbits.RA0
#define MON5V_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define MON5V_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define MON5V_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define MON5V_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define MON5V_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define MON5V_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define MON5V_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define MON5V_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set RA1 aliases
#define BATMON_TRIS                 TRISAbits.TRISA1
#define BATMON_LAT                  LATAbits.LATA1
#define BATMON_PORT                 PORTAbits.RA1
#define BATMON_WPU                  WPUAbits.WPUA1
#define BATMON_OD                   ODCONAbits.ODCA1
#define BATMON_ANS                  ANSELAbits.ANSELA1
#define BATMON_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define BATMON_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define BATMON_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define BATMON_GetValue()           PORTAbits.RA1
#define BATMON_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define BATMON_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define BATMON_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define BATMON_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define BATMON_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define BATMON_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define BATMON_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define BATMON_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set RA2 aliases
#define IO_RA2_TRIS                 TRISAbits.TRISA2
#define IO_RA2_LAT                  LATAbits.LATA2
#define IO_RA2_PORT                 PORTAbits.RA2
#define IO_RA2_WPU                  WPUAbits.WPUA2
#define IO_RA2_OD                   ODCONAbits.ODCA2
#define IO_RA2_ANS                  ANSELAbits.ANSELA2
#define IO_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IO_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IO_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IO_RA2_GetValue()           PORTAbits.RA2
#define IO_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IO_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IO_RA2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define IO_RA2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define IO_RA2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define IO_RA2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define IO_RA2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define IO_RA2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA3 aliases
#define IO_RA3_TRIS                 TRISAbits.TRISA3
#define IO_RA3_LAT                  LATAbits.LATA3
#define IO_RA3_PORT                 PORTAbits.RA3
#define IO_RA3_WPU                  WPUAbits.WPUA3
#define IO_RA3_OD                   ODCONAbits.ODCA3
#define IO_RA3_ANS                  ANSELAbits.ANSELA3
#define IO_RA3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define IO_RA3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define IO_RA3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define IO_RA3_GetValue()           PORTAbits.RA3
#define IO_RA3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define IO_RA3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define IO_RA3_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define IO_RA3_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define IO_RA3_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define IO_RA3_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define IO_RA3_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define IO_RA3_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set RA4 aliases
#define AFU0_TRIS                 TRISAbits.TRISA4
#define AFU0_LAT                  LATAbits.LATA4
#define AFU0_PORT                 PORTAbits.RA4
#define AFU0_WPU                  WPUAbits.WPUA4
#define AFU0_OD                   ODCONAbits.ODCA4
#define AFU0_ANS                  ANSELAbits.ANSELA4
#define AFU0_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define AFU0_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define AFU0_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define AFU0_GetValue()           PORTAbits.RA4
#define AFU0_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define AFU0_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define AFU0_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define AFU0_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define AFU0_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define AFU0_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define AFU0_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define AFU0_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RA5 aliases
#define AFU1_TRIS                 TRISAbits.TRISA5
#define AFU1_LAT                  LATAbits.LATA5
#define AFU1_PORT                 PORTAbits.RA5
#define AFU1_WPU                  WPUAbits.WPUA5
#define AFU1_OD                   ODCONAbits.ODCA5
#define AFU1_ANS                  ANSELAbits.ANSELA5
#define AFU1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define AFU1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define AFU1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define AFU1_GetValue()           PORTAbits.RA5
#define AFU1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define AFU1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define AFU1_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define AFU1_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define AFU1_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define AFU1_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define AFU1_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define AFU1_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RA6 aliases
#define AFU3_TRIS                 TRISAbits.TRISA6
#define AFU3_LAT                  LATAbits.LATA6
#define AFU3_PORT                 PORTAbits.RA6
#define AFU3_WPU                  WPUAbits.WPUA6
#define AFU3_OD                   ODCONAbits.ODCA6
#define AFU3_ANS                  ANSELAbits.ANSELA6
#define AFU3_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define AFU3_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define AFU3_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define AFU3_GetValue()           PORTAbits.RA6
#define AFU3_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define AFU3_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define AFU3_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define AFU3_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define AFU3_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define AFU3_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define AFU3_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define AFU3_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set RA7 aliases
#define AFU2_TRIS                 TRISAbits.TRISA7
#define AFU2_LAT                  LATAbits.LATA7
#define AFU2_PORT                 PORTAbits.RA7
#define AFU2_WPU                  WPUAbits.WPUA7
#define AFU2_OD                   ODCONAbits.ODCA7
#define AFU2_ANS                  ANSELAbits.ANSELA7
#define AFU2_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define AFU2_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define AFU2_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define AFU2_GetValue()           PORTAbits.RA7
#define AFU2_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define AFU2_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define AFU2_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define AFU2_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define AFU2_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define AFU2_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define AFU2_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define AFU2_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set RB0 aliases
#define IO_RB0_TRIS                 TRISBbits.TRISB0
#define IO_RB0_LAT                  LATBbits.LATB0
#define IO_RB0_PORT                 PORTBbits.RB0
#define IO_RB0_WPU                  WPUBbits.WPUB0
#define IO_RB0_OD                   ODCONBbits.ODCB0
#define IO_RB0_ANS                  ANSELBbits.ANSELB0
#define IO_RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define IO_RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define IO_RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define IO_RB0_GetValue()           PORTBbits.RB0
#define IO_RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define IO_RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define IO_RB0_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define IO_RB0_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define IO_RB0_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define IO_RB0_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define IO_RB0_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define IO_RB0_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB1 aliases
#define TP3_TRIS                 TRISBbits.TRISB1
#define TP3_LAT                  LATBbits.LATB1
#define TP3_PORT                 PORTBbits.RB1
#define TP3_WPU                  WPUBbits.WPUB1
#define TP3_OD                   ODCONBbits.ODCB1
#define TP3_ANS                  ANSELBbits.ANSELB1
#define TP3_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define TP3_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define TP3_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define TP3_GetValue()           PORTBbits.RB1
#define TP3_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define TP3_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define TP3_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define TP3_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define TP3_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define TP3_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define TP3_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define TP3_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 aliases
#define IO_RB2_TRIS                 TRISBbits.TRISB2
#define IO_RB2_LAT                  LATBbits.LATB2
#define IO_RB2_PORT                 PORTBbits.RB2
#define IO_RB2_WPU                  WPUBbits.WPUB2
#define IO_RB2_OD                   ODCONBbits.ODCB2
#define IO_RB2_ANS                  ANSELBbits.ANSELB2
#define IO_RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define IO_RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define IO_RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define IO_RB2_GetValue()           PORTBbits.RB2
#define IO_RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define IO_RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define IO_RB2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define IO_RB2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define IO_RB2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define IO_RB2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define IO_RB2_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define IO_RB2_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB3 aliases
#define TP1_TRIS                 TRISBbits.TRISB3
#define TP1_LAT                  LATBbits.LATB3
#define TP1_PORT                 PORTBbits.RB3
#define TP1_WPU                  WPUBbits.WPUB3
#define TP1_OD                   ODCONBbits.ODCB3
#define TP1_ANS                  ANSELBbits.ANSELB3
#define TP1_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define TP1_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define TP1_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define TP1_GetValue()           PORTBbits.RB3
#define TP1_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define TP1_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define TP1_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define TP1_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define TP1_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define TP1_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define TP1_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define TP1_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 aliases
#define IO_RB4_TRIS                 TRISBbits.TRISB4
#define IO_RB4_LAT                  LATBbits.LATB4
#define IO_RB4_PORT                 PORTBbits.RB4
#define IO_RB4_WPU                  WPUBbits.WPUB4
#define IO_RB4_OD                   ODCONBbits.ODCB4
#define IO_RB4_ANS                  ANSELBbits.ANSELB4
#define IO_RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RB4_GetValue()           PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RB4_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RB4_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define IO_RB4_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define IO_RB4_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB5 aliases
#define TP2_TRIS                 TRISBbits.TRISB5
#define TP2_LAT                  LATBbits.LATB5
#define TP2_PORT                 PORTBbits.RB5
#define TP2_WPU                  WPUBbits.WPUB5
#define TP2_OD                   ODCONBbits.ODCB5
#define TP2_ANS                  ANSELBbits.ANSELB5
#define TP2_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define TP2_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define TP2_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define TP2_GetValue()           PORTBbits.RB5
#define TP2_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define TP2_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define TP2_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define TP2_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define TP2_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define TP2_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define TP2_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define TP2_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RB6 aliases
#define IO_RB6_TRIS                 TRISBbits.TRISB6
#define IO_RB6_LAT                  LATBbits.LATB6
#define IO_RB6_PORT                 PORTBbits.RB6
#define IO_RB6_WPU                  WPUBbits.WPUB6
#define IO_RB6_OD                   ODCONBbits.ODCB6
#define IO_RB6_ANS                  ANSELBbits.ANSELB6
#define IO_RB6_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_RB6_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_RB6_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_RB6_GetValue()           PORTBbits.RB6
#define IO_RB6_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define IO_RB6_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define IO_RB6_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define IO_RB6_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define IO_RB6_SetAnalogMode()      do { ANSELBbits.ANSELB6 = 1; } while(0)
#define IO_RB6_SetDigitalMode()     do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set RB7 aliases
#define IO_RB7_TRIS                 TRISBbits.TRISB7
#define IO_RB7_LAT                  LATBbits.LATB7
#define IO_RB7_PORT                 PORTBbits.RB7
#define IO_RB7_WPU                  WPUBbits.WPUB7
#define IO_RB7_OD                   ODCONBbits.ODCB7
#define IO_RB7_ANS                  ANSELBbits.ANSELB7
#define IO_RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RB7_GetValue()           PORTBbits.RB7
#define IO_RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define IO_RB7_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define IO_RB7_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define IO_RB7_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define IO_RB7_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define IO_RB7_SetAnalogMode()      do { ANSELBbits.ANSELB7 = 1; } while(0)
#define IO_RB7_SetDigitalMode()     do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set RC0 aliases
#define AFU4_TRIS                 TRISCbits.TRISC0
#define AFU4_LAT                  LATCbits.LATC0
#define AFU4_PORT                 PORTCbits.RC0
#define AFU4_WPU                  WPUCbits.WPUC0
#define AFU4_OD                   ODCONCbits.ODCC0
#define AFU4_ANS                  ANSELCbits.ANSELC0
#define AFU4_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define AFU4_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define AFU4_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define AFU4_GetValue()           PORTCbits.RC0
#define AFU4_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define AFU4_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define AFU4_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define AFU4_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define AFU4_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define AFU4_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define AFU4_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define AFU4_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 aliases
#define AFU5_TRIS                 TRISCbits.TRISC1
#define AFU5_LAT                  LATCbits.LATC1
#define AFU5_PORT                 PORTCbits.RC1
#define AFU5_WPU                  WPUCbits.WPUC1
#define AFU5_OD                   ODCONCbits.ODCC1
#define AFU5_ANS                  ANSELCbits.ANSELC1
#define AFU5_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define AFU5_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define AFU5_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define AFU5_GetValue()           PORTCbits.RC1
#define AFU5_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define AFU5_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define AFU5_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define AFU5_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define AFU5_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define AFU5_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define AFU5_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define AFU5_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set RC2 aliases
#define AFU6_TRIS                 TRISCbits.TRISC2
#define AFU6_LAT                  LATCbits.LATC2
#define AFU6_PORT                 PORTCbits.RC2
#define AFU6_WPU                  WPUCbits.WPUC2
#define AFU6_OD                   ODCONCbits.ODCC2
#define AFU6_ANS                  ANSELCbits.ANSELC2
#define AFU6_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define AFU6_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define AFU6_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define AFU6_GetValue()           PORTCbits.RC2
#define AFU6_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define AFU6_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define AFU6_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define AFU6_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define AFU6_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define AFU6_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define AFU6_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define AFU6_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 aliases
#define AFU7_TRIS                 TRISCbits.TRISC3
#define AFU7_LAT                  LATCbits.LATC3
#define AFU7_PORT                 PORTCbits.RC3
#define AFU7_WPU                  WPUCbits.WPUC3
#define AFU7_OD                   ODCONCbits.ODCC3
#define AFU7_ANS                  ANSELCbits.ANSELC3
#define AFU7_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define AFU7_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define AFU7_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define AFU7_GetValue()           PORTCbits.RC3
#define AFU7_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define AFU7_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define AFU7_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define AFU7_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define AFU7_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define AFU7_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define AFU7_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define AFU7_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 aliases
#define CONTROLBAT_TRIS                 TRISCbits.TRISC4
#define CONTROLBAT_LAT                  LATCbits.LATC4
#define CONTROLBAT_PORT                 PORTCbits.RC4
#define CONTROLBAT_WPU                  WPUCbits.WPUC4
#define CONTROLBAT_OD                   ODCONCbits.ODCC4
#define CONTROLBAT_ANS                  ANSELCbits.ANSELC4
#define CONTROLBAT_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define CONTROLBAT_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define CONTROLBAT_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define CONTROLBAT_GetValue()           PORTCbits.RC4
#define CONTROLBAT_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define CONTROLBAT_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define CONTROLBAT_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define CONTROLBAT_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define CONTROLBAT_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define CONTROLBAT_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define CONTROLBAT_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define CONTROLBAT_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 aliases
#define CONTROL5V_TRIS                 TRISCbits.TRISC5
#define CONTROL5V_LAT                  LATCbits.LATC5
#define CONTROL5V_PORT                 PORTCbits.RC5
#define CONTROL5V_WPU                  WPUCbits.WPUC5
#define CONTROL5V_OD                   ODCONCbits.ODCC5
#define CONTROL5V_ANS                  ANSELCbits.ANSELC5
#define CONTROL5V_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define CONTROL5V_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define CONTROL5V_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define CONTROL5V_GetValue()           PORTCbits.RC5
#define CONTROL5V_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define CONTROL5V_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define CONTROL5V_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define CONTROL5V_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define CONTROL5V_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define CONTROL5V_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define CONTROL5V_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define CONTROL5V_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 aliases
#define REDLED_TRIS                 TRISCbits.TRISC6
#define REDLED_LAT                  LATCbits.LATC6
#define REDLED_PORT                 PORTCbits.RC6
#define REDLED_WPU                  WPUCbits.WPUC6
#define REDLED_OD                   ODCONCbits.ODCC6
#define REDLED_ANS                  ANSELCbits.ANSELC6
#define REDLED_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define REDLED_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define REDLED_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define REDLED_GetValue()           PORTCbits.RC6
#define REDLED_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define REDLED_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define REDLED_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define REDLED_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define REDLED_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define REDLED_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define REDLED_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define REDLED_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 aliases
#define GRNLED_TRIS                 TRISCbits.TRISC7
#define GRNLED_LAT                  LATCbits.LATC7
#define GRNLED_PORT                 PORTCbits.RC7
#define GRNLED_WPU                  WPUCbits.WPUC7
#define GRNLED_OD                   ODCONCbits.ODCC7
#define GRNLED_ANS                  ANSELCbits.ANSELC7
#define GRNLED_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define GRNLED_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define GRNLED_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define GRNLED_GetValue()           PORTCbits.RC7
#define GRNLED_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define GRNLED_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define GRNLED_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define GRNLED_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define GRNLED_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define GRNLED_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define GRNLED_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define GRNLED_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/