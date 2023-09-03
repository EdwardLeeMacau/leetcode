#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <string>
#include <vector>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens);
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped);
};

#endif /* !SOLUTION_H_ */
