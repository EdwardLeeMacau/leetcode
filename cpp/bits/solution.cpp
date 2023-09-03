#include "solution.h"

int Solution::hammingWeight(uint32_t n) 
{
    int count = 0;
    
    while (n) {
        if (n & 0x1) { ++count; }
        n = n >> 1;
    }

    return count;
}
