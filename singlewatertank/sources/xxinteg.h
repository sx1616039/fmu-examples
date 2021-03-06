/**********************************************************
 * This file is generated by 20-sim ANSI-C Code Generator
 *
 *  file:  src\xxinteg.h
 *  model: Watertank
 *  expmt: Watertank
 *  date:  September 17, 2015
 *  time:  7:49:50 pm
 *  user:  INTO-CPS
 *  from:  20-sim 4.5 Professional Single
 *  build: 4.5.1.5561
 **********************************************************/

/* This file describes the integration methods
that are supplied for computation.

   Currently only Euler, RungeKutta2 and RungeKutta4 are supplied,
   but it is easy for the user to add their own
   integration methods with these two as an example.
*/

#ifndef XX_INTEG_H
#define XX_INTEG_H

/* 20-sim include files */
#include "xxtypes.h"

/* the chosen integration method */
#define RungeKutta4_METHOD

/* the integration methods */
#ifdef Discrete_METHOD
void XXDiscreteInitialize (void);
void XXDiscreteTerminate (void);
void XXDiscreteStep (void);
#endif 

#ifdef Euler_METHOD
void XXEulerInitialize (void);
void XXEulerTerminate (void);
void XXEulerStep (void);
#endif 

#ifdef RungeKutta2_METHOD
void XXRungeKutta2Initialize (void);
void XXRungeKutta2Terminate (void);
void XXRungeKutta2Step (void);
#endif

#ifdef RungeKutta4_METHOD
void XXRungeKutta4Initialize (void);
void XXRungeKutta4Terminate (void);
void XXRungeKutta4Step (void);
#endif

extern XXBoolean xx_major;

#endif

