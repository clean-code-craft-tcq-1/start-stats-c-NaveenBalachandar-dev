#include "stats.h"

typedef struct Stats 
{
 int average;
 int min;
 int max;
};


struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
}

//Test code to check test case 
int emailAlertCallCount = 1;
int ledAlertCallCount = 1;
