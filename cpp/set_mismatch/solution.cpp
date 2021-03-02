#include "solution.h"

/**
 * @time-complexity  O(N), N stands for the length of nums
 * @space-complexity O(N), N stands for the length of nums
 */
std::vector<int> findErrorNums(std::vector<int>& nums)
{
	int size = nums.size();

	vector<int> buf(size + 1, 1);
	vector<int> ans(2, 0);
	
	for (int i = 0; i < size; ++i) {
		--buf[nums[i]];
	}
	
	for (int i = 1; i < size + 1; ++i) {
		if (buf[i] == -1) {
			ans[0] = i;
		}
		
		if (buf[i] == 1) {
			ans[1] = i;
		}
	}

	return ans;
}

