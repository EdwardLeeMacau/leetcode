#include "solution.h"

#include <math.h>

using namespace std;

vector<int> Solution::sortedSquares(vector<int>& nums) {
    vector<int> squares(nums.size(), 0);
    int size, left, right, cur;
    size = nums.size();
    
    for (left = -1; left < size - 1; ++left) {
        if (nums[left + 1] >= 0) {
            break;
        }
    }
    
    for (right = size; right > 0; --right) {
        if (nums[right - 1] < 0) {
            break;
        }
    }
    
    cur = 0;
    while (left != -1 && right != size) {
        if (-nums[left] > nums[right]) {
            squares[cur++] = pow(nums[right++], 2);
        } else {
            squares[cur++] = pow(nums[left--], 2);
        }
    }

    while (right != size) {
        squares[cur++] = pow(nums[right++], 2);
    }
    
    while (left != -1) {
        squares[cur++] = pow(nums[left--], 2);
    }

    return squares;
}
