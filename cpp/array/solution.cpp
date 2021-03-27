#include "solution.h"

#include <math.h>

/**
 * @score (runtime / memory) (74.21% / 96.36%)
 */
int sumOddLengthSubarrays(std::vector<int>& arr)
{
    int ans, i, j, len, size = arr.size();

    ans = 0;
    for (len = 1; len < size; len += 2) {
        for (i = 0; i < size - len + 1; ++i) {
            for (j = 0; j < len; ++j) {
                ans += arr[i + j];
            }
        }
    }

    return ans;
}

std::vector<int> Solution::shuffle(std::vector<int>& nums, int n) {
    std::vector<int> ans(nums.size(), 0);
    std::vector<int>::iterator iter = ans.begin(), end = ans.end();
    int i;

    for (i = 0; i < n; ++i) {
        *(iter++) = nums[i];
        *(iter++) = nums[i + n];
    }

    return ans;
}

std::vector<int> Solution::sortedSquares(std::vector<int>& nums) {
    std::vector<int> squares(nums.size(), 0);
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
