/******************************************************************************/
/***    \file        stats.c
***     \author  Naveen Balachandar                 
***
***     \brief       Application file for compute statistics
***/       
/*****************************************************************************/

/*=============================================================================
=======                            INCLUDES                             =======
=============================================================================*/
#include "stats.h"

/*=============================================================================
=======                            Variables                            =======
=============================================================================*/
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

/*=============================================================================
=======                       Local Functions                           =======
=============================================================================*/
static float compute_avgerage_f(const float* numberset, int setlength);
static float compute_MinNum_f(const float* numberset, int setlength);
static float compute_MaxNum_f(const float* numberset, int setlength);


/*---------------------------------------------------------------------------*/
/*     FUNCTION:    compute_statistics
 */
/*!    \brief       compute statistics like average ,Minimum and maximum
 *
 *     \param       numberset,setlength
 *     \returns     structure statisics refrence
 *
*//*------------------------------------------------------------------------*/
struct Stats compute_statistics(const float* numberset, int setlength) {
    
    Stats s; /*Instance to structure*/
    
    /*computing average*/
    s.average = compute_avgerage_f(numberset ,setlength);
   /*computing  Minimum number in array*/
    s.min = compute_MinNum_f(numberset ,setlength); 
   /*computing  maximum number in array*/
    s.max = compute_MaxNum_f(numberset ,setlength);
    
    return s;
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    compute_avgerage_f
 */
/*!    \brief       compute statistics - average ,
 *
 *     \param       numberset,setlength
 *     \returns     average result
 *
*//*------------------------------------------------------------------------*/
static float compute_avgerage_f(const float* numberset, int setlength)
{
  float sum =0.0;  
  static float avg = 0.0;  
  int count;
  
   /*calculating sum*/
  for (count=0 ;count<setlength;count++)  
  {
      sum +=numberset[count];
  }
  /*calculating avg*/  
  avg = (sum/setlength);
    
   return avg; 
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    compute_MinNum_f
 */
/*!    \brief       compute statistics - Minnumber ,
 *
 *     \param       numberset,setlength
 *     \returns     minnumber result
 *
*//*------------------------------------------------------------------------*/
static float compute_MinNum_f(const float* numberset, int setlength)
{
  static float minNum = numberset[0];  
  int count;
  
   /*calculating Min number in array*/
  for (count=1 ;count<setlength;count++)  
  {
      if (minNum > numberset[count])
      {
         minNum = numberset[count];
      }
  }
   return minNum; 
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    compute_MaxNum_f
 */
/*!    \brief       compute statistics - Maximum number ,
 *
 *     \param       numberset,setlength
 *     \returns     Maximum number result
 *
*//*------------------------------------------------------------------------*/
static float compute_MaxNum_f(const float* numberset, int setlength)
{
  static float Maxnum = numberset[0];  
  int count;
  
   /*calculating Min number in array*/
  for (count=1 ;count<setlength;count++)  
  {
      if (Maxnum < numberset[count])
      {
         Maxnum = numberset[count];
      }
  }
   return Maxnum; 
}

/*---------------------------------------------------------------------------*/
/*     FUNCTION:    check_and_alert
*/
/*!    \brief       Raises alerts when max is greater than threshold
*
*
*     \param       maxThreshold_f          - Maximum allowed threshold value
*     \param       alerter_funcptr         - Function pointer for alert functions
*     \param       computedStats_s         - Statistic result values
*     \returns     void
*//*------------------------------------------------------------------------*/
void check_and_alert(float maxThreshold_f, alerter_funcptr alerters[], struct Stats computedStats_s) {
    
    
    /*Check maimum number exceeds threshold*/
    if(computedStats_s.max > maxThreshold_f)
    { 
            /*email and LED alert*/      
            alerters[0]();
            alerters[1]();
    }
}

