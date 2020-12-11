#include "solution.h"

#include <iostream>

using namespace std;

vector<int> Solution::sumZero(int n)
{
    vector<int> ret(n, 0);
    int tmp, i;

    tmp = 0;
    for (i = n / 2 - 1; i >= 0; --i) {
        ret[i] = ++tmp;
    }

    tmp = 0;
    i = (n % 2)? (n / 2 + 1) : (n / 2);
    for (; i < n; ++i) {
        ret[i] = --tmp;
    }

    return ret;
}
