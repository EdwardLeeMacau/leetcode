#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <string>
#include <vector>

class Solution
{
public:
    int kthFactor(int n, int k);
    int distributeCandies(std::vector<int>& candyType);
    int scoreOfParentheses(std::string S);
    int numPairsDivisibleBy60(std::vector<int>& time);
    bool increasingTriplet(std::vector<int>& nums);
    std::vector<int> sumZero(int);
    std::vector<int> findErrorNums(std::vector<int>& nums);
};

#endif /* !SOLUTION_H_ */
