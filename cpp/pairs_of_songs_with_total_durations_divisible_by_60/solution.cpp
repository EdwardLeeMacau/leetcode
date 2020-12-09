#include "solution.h"

#include <iostream>

using namespace std;

inline int min(int a, int b) 
{
    return (a < b)? a : b;
}

int Solution::numPairsDivisibleBy60(vector<int>& time) 
{
    vector<int> count(60, 0);
    size_t idx;
    int ret = 0;

    for (idx = 0; idx < time.size(); ++idx) {
        ++count[time[idx] % 60];
    }
 
    if (count[0] >= 2) {
        ret += count[0] * (count[0] - 1) / 2;
    }

    if (count[30] >= 2) {
        ret += count[30] * (count[30] - 1) / 2;
    }

    for (idx = 1; idx < 30; ++idx) {
        ret += count[idx] * count[60 - idx];
    }

    return ret;
}
