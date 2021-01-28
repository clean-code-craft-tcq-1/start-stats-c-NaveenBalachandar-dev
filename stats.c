#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    Stats s;
    
    s.average = setlength;
    s.min = numberset[3];
    s.max = 0;
    retrun s;
}

//Test code to check test case 
int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
