#include "solution.h"

using namespace std;

bool Solution::increasingTriplet(vector<int>& nums)
{
    int cur, i = 0, j, k;
    
    /** If length of vector is less than 3 */
    if (nums.size() < 3) {
        return false;
    }

    /** Search for the first local minimal */
    while ((i < nums.size() - 1) && (nums[i + 1] <= nums[i])) {
        ++i;
    }

    /*< Search for proper index i, j, k */
    k = i;
    j = i + 1;
    cur = j + 1;
    while (cur < nums.size()) {
        if (nums[j] < nums[cur]) {
            return true;
        }

        if (nums[i] < nums[cur] || (k != i)) {
            j = cur;
            i = k;
        } else if (nums[cur] < nums[k]) {
            k = cur;
        }

        ++cur;
    }

    return false;
}
