#include "stats.h"

static float compute_avgerage_f(const float* numberset, int setlength);

struct Stats compute_statistics(const float* numberset, int setlength) {
    
    Stats s; /*Instance to structure*/
    
    /*computing average*/
    s.average = compute_avgerage_f(numberset ,setlength);
   
    s.min = numberset[1]; /*to be done*/
    s.max = numberset[0]; /*to be done*/
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

//Test code to check test case 
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
