/* 
 * File:   global_defs.h
 * Author: Mike
 *
 * Created on May 16, 2021, 1:45 PM
 */

#ifndef GLOBAL_DEFS_H
#define	GLOBAL_DEFS_H

#ifdef	__cplusplus
extern "C" {
#endif

#pragma warning disable 520  // Turns off the Function Not Called Warning
#pragma warning disable 2053  // Turns off the Function Not Called Warning - Inline functions
    
#include "mcc_generated_files/system/system.h"
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
    
#define TRUE 1
#define FALSE 0

    
#define HEARTBEAT_INTERVAL  (0.01)  // seconds for interrupt from systick timer
#define LED_HEARTBEAT_INTERVAL 50  // Interval for heartbeat tick - 50 = 500ms @ 10ms tick
    
#define A2D_UPDATE_INTERVAL 1 // New A2D reading every 20 ms with 10ms Tic - each of 3 channels then gets read every 30ms
    
#define LORA_CURRENT_DEFAULT_TIMEOUT (3000)  // 30000 = 5 minutes if no LoRa we will pull the plug
//#define LORA_TIME_DEFAULT_TIMEOUT ((uint24_t)((24*3600)/HEARTBEAT_INTERVAL))  // 24 hours is default time for time base power reset - changed by dipswitches
#define LORA_TIME_DEFAULT_TIMEOUT 8640000
    
    // Note - in the reading of the dipswitches 5 & 6, I invert the bits. An open swithc is considered 'off' but will read as a '1' so 
    // I invert to make the table below easier to understand....
//#define LORA_TIME_RESET_0   (8640000) // default time when cong switches AFU 5 & 6 are open (factory default) - 24 hours
//#define LORA_TIME_RESET_1   (4320000) // reset every 12 hours
//#define LORA_TIME_RESET_2   (2160000)  // reset every 6 hours
//#define LORA_TIME_RESET_3   (1500)  // reset every 15 seconds - used for testing....
    // Note - need the 'long' designator on 1 of the numbers to force a 32 bit result - otherwise throws an integer overflow error...
#define LORA_TIME_RESET_0   ((uint24_t)((24*3600l)/0.01)) // default time when cong switches AFU 5 & 6 are open (factory default) - 24 hours
#define LORA_TIME_RESET_1   ((uint24_t)((12*3600l)/HEARTBEAT_INTERVAL)) // reset every 12 hours
#define LORA_TIME_RESET_2   ((uint24_t)((6*3600l)/HEARTBEAT_INTERVAL))  // reset every 6 hours
#define LORA_TIME_RESET_3   ((uint24_t)(20l/HEARTBEAT_INTERVAL))  // reset every 15 seconds - used for testing....

    
    
#define LORA_POWER_OFF_TIME 200 // pull power for 2 seconds
    
#define AVERAGER_TIME_CONSTANT  8  // This is like the time constant of the averaging filter. This is how many shifts (divide / 2)
                                    // we reduce any difference in the current reading to long term average
                                    // a value of 10 means we take 1/1024th of the difference on each calculation
                                    // so with a 10ms loop, it will take about 10 seconds to settle to 99% with a step change.
                                    // 11 would be 1/2048 so ~20 seconds, etc.
                                    // max is 15
                                    // I settled on 8 which give about a 30 second period to settle for a step change

#ifdef	__cplusplus
}
#endif

#endif	/* GLOBAL_DEFS_H */

