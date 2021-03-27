#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <string>
#include <vector>

class Solution {
public:
    int removePalindromeSub(std::string);
    bool isValidPaentheses(std::string s);
    std::string toLowerCase(std::string str);
    std::string longestCommonPrefix(std::vector<std::string>& strs);
};

#endif /* !SOLUTION_H_ */
