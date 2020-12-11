#include "solution.h"

#include <iostream>

using namespace std;

int Solution::countNegatives(vector<vector<int>>& grid) 
{
    size_t maxRow = grid.size();
    size_t col = grid[0].size() - 1;
    size_t row = 0;

    int rowCount = 0;
    int ret = 0;

    while (row < maxRow) {
        while (col >= 0 && grid[row][col] < 0) {
            --col;
            ++rowCount;
        }

        ret += rowCount;
        ++row;
    }

    return ret;
}
