#include "stats.h"

static float compute_avgerage_f(const float* numberset, int setlength);
static float compute_MinNum_f(const float* numberset, int setlength);
static float compute_MaxNum_f(const float* numberset, int setlength);

struct Stats compute_statistics(const float* numberset, int setlength) {
    
    Stats s; /*Instance to structure*/
    
    /*computing average*/
    s.average = compute_avgerage_f(numberset ,setlength);
   /*computing average*/
    s.min = compute_MinNum_f(numberset ,setlength); 
    /*computing average*/
    s.max = compute_MaxNum_f(numberset ,setlength);
    return s;
}

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

    /*calculating avg*/  
    
   return minNum; 
}

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

    /*calculating avg*/  
    
   return Maxnum; 
}
//Test code to check test case 
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
