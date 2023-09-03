#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
public:
    using Coord = tuple<int, int>;
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
    {
        const int numRows = matrix.size();
        const int numCols = matrix[0].size();

        vector<vector<int>> ans(numRows, vector<int>(numCols, -1));
        queue<Coord> q1, q2, *curr, *next;
        int dist = 0;

        curr = &q1; next = &q2;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (matrix[i][j] == 0) {
                    ans[i][j] = 0; curr->emplace(i, j);
                }
            }
        }

        for (dist = 1; true; ++dist) {
            while (!curr->empty()) {
                int i, j;
                std::tie(i, j) = curr->front();
                curr->pop();

                if (i > 0 && ans[i - 1][j] == -1) {
                    ans[i - 1][j] = dist; next->emplace(i - 1, j);
                }
                if (i < numRows - 1 && ans[i + 1][j] == -1) {
                    ans[i + 1][j] = dist; next->emplace(i + 1, j);
                }
                if (j > 0 && ans[i][j - 1] == -1) {
                    ans[i][j - 1] = dist; next->emplace(i, j - 1);
                }
                if (j < numCols - 1 && ans[i][j + 1] == -1) {
                    ans[i][j + 1] = dist; next->emplace(i, j + 1);
                }
            }

            if (next->empty()) {
                break;
            }

            swap(curr, next);
        }

        return ans;
    }
};