/* 
 * File:   misc.h
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef MISC_H
#define	MISC_H

#include <xc.h> // include processor files - each processor file is guarded. 
#include "global_defs.h"

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate



// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

void IncSysTick(void);
void ClearSysTick(void);
uint16_t GetSysTick(void);
void DoHeartBeat(void);
void DoA2D(void);
void A2DIntHandler(void);
uint16_t GetSupplyVoltage(void);


void TurnOn5v(void);
void TurnOff5v(void);
void TurnOnBat(void);
void TurnOffBat(void);

void PetTheDog(void);

void DoLongTermAverage5v(uint16_t currentA2D);
void SetNew5VDACThreshold(void);

void CheckCurrentMonitors(void);
void ResetLoRaTimer(void);
void PullThePlug(void);

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* MISC_H */

