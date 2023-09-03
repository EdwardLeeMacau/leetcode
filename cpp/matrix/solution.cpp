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

/**
 * @constraints
 * - 2 <= rows, cols <= 70
 * - 0 <= grid[i][j] <= 100
 */
int Solution::cherryPickup(vector<vector<int> >& grid) 
{
    int numRows = grid.size(), numCols = grid[0].size();
    // vector<vector<int> > dp_matrix(vector<int>(grid[0].size(), 0), grid.size());

    return 0;
}

int Solution::countNegatives(vector<vector<int> >& grid) 
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

bool Solution::isValidSudoku(std::vector<std::vector<char> >& board)
{
    return false;
}