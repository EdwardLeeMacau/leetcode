#include "solution.h"

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
