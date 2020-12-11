#include "solution.h"

#include <iostream>

using namespace std;

int Solution::diagonalSum(vector<vector<int>>& mat) 
{
    int ret = 0;
    int n = mat.size();
    int i;

    for (i = 0; i < n; ++i) {
        ret += mat[i][i];
    }

    for (i = 0; i < n; ++i) {
        ret += mat[i][n - i - 1];
    }

    if (n % 2) {
        i = n / 2;
        ret -= mat[i][i];
    }

    return ret;
}