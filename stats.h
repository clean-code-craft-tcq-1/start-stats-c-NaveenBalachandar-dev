/******************************************************************************/
/***    \file        stats.h
***     \author  Naveen Balachandar                 
***
***     \brief       Header for stats.h
***/       
/*****************************************************************************/

/*=============================================================================
=======                            INCLUDES                             =======
=============================================================================*/
#include <stdlib.h>

/*=============================================================================
=======                       TYPES                       =======
=============================================================================*/

/*structure for computing statistics */
struct Stats 
{
 float average; 
 float min;
 float max;
};

/*=============================================================================
=======                      COMMON FUNCTIONS                            =======
=============================================================================*/
struct Stats compute_statistics(const float* numberset, int setlength);
typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);

/*=============================================================================
=======                      COMMON VARIABLES                           =======
=============================================================================*/
extern int emailAlertCallCount;
extern int ledAlertCallCount;
