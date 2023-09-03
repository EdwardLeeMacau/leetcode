#include "solution.h"

#include <stack>

/**
 * @brief answer is in range [0, 2]
 * @score (runtime / memory) (100.00% / 91.64%)
 * @time-complexity O(N). N is the length of string
 * @space-complexity O(1).
 */
int Solution::removePalindromeSub(std::string s)
{
    std::string::const_iterator liter = s.cbegin();
    std::string::const_reverse_iterator riter = s.crbegin();

    int size = s.length();

    if (!size) {
        return 0;
    }

    while ((size > 0) && (*liter == *riter)) {
        size -= 2; ++liter; ++riter;
    }

    return (size > 1)? 2: 1;
}

/**
 * @score (runtime / memory) (100.00% / 73.23%)
 */
bool isValidPaentheses(std::string s)
{
    std::stack<char> stack;
    int size = s.size();
    char c;

    if (size % 2) {
        return false;
    }

    for (int i = 0; i < size; ++i) {
        switch ((c = s[i])) {
        case '(':
        case '[':
        case '{':
            stack.push(c);
            break;

        case ')':
            c = '('; goto check;
        case ']':
            c = '['; goto check;
        case '}':
            c = '{';

check:
        if (stack.empty() || c != stack.top()) {
            return false;
        }

        stack.pop(); break;

        default:
            // Raise exception if need;
            break;
        }
    }

    return (stack.empty())? true: false;
}

/**
 * @score (runtime / memory) (100.00% / 32.67%)
 */
std::string Solution::toLowerCase(std::string str)
{
    std::string::iterator iter, end = str.end();

    for (iter = str.begin(); iter != end; ++iter) {
        if (*iter <= 0x5B) {
            *iter += 0x20;
        }
    }

    return str;
}

/**
 * @brief Understanding basic usage of std::string
 * @score (runtime / memory) (100.00% / 63.72%)
 */
std::string Solution::longestCommonPrefix(std::vector<std::string>& strs)
{
    std::vector<std::string>::iterator iter, end = strs.end();
    std::string str;
    int i, maxSize = 0;
    char c;

    for (iter = strs.begin(); iter != end; ++iter) {
        if (maxSize < iter->size()) {
            maxSize = iter->size();
        }
    }

    for (i = 0; i < maxSize; ++i) {
        c = strs[0][i];

        for (iter = strs.begin(); iter != end; ++iter) {
            if (c != (*iter)[i]) {
                return str;
            }
        }

        str.push_back(c);
    }

    return str;
}