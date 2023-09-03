#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <vector>

class Solution {
public:
    int diagonalSum(std::vector<std::vector<int> >& );
    int cherryPickup(std::vector<std::vector<int> >& grid);
    int countNegatives(std::vector<std::vector<int> >& grid);
    bool isValidSudoku(std::vector<std::vector<char> >& board);
};

#endif /* !SOLUTION_H_ */