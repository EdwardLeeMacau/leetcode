#include "solution.h"

#include <stack>
#include <iostream>

int Solution::evalRPN(std::vector<std::string>& tokens)
{
    std::stack<std::string> stack;
    std::vector<std::string>::iterator iter = tokens.begin(), end = tokens.end();
    int l, r;

    for (; iter != end; ++iter) {
        // TODO
    }

    return 0;
}

/**
 * @details (Algorithm Descritpion)
 */
bool Solution::validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped)
{
    int length = pushed.size();
    int i = 0, j = 0;
    std::stack<int> buf;

    return false;
}
