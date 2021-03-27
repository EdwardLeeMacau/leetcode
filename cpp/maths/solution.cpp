#include "solution.h"

#include <algorithm>
#include <stack>
#include <unordered_map>

inline int min(int a, int b)
{
    return (a < b)? a : b;
}

int Solution::kthFactor(int n, int k)
{
    return 0;
}

/**
 * @brief skipped
 * @score (runtime / memory) (100.00% / 86.04%)
 */
int romanToInt(std::string s)
{
    return 0;
}

int Solution::findKthPositive(std::vector<int>& arr, int k)
{
    int start, mid, end = arr.size();

    /** Check array size */
    if (0 == end) {
        return k;
    }

    /** If k-th missing positive is out of the array */
    if (end + k > arr[end - 1]) {
        return end + k;
    }

    mid = (start + end) / 2;
    while (arr[mid - 1] > mid + k) {
        // TODO
    }
    return k;
}

/**
 * @brief Learning how to use unordered_map / hashset (TODO)
 * @score (runtime / memory) (89.92% / 55.69%)
 * @time-complexity O(N). N stand for the length of input vector.
 * @notes Operation read / write / find in unordered_map is O(1)
 */
int Solution::distributeCandies(std::vector<int>& candyType)
{
    std::unordered_map<int, int> umap;
    int i, size = candyType.size();

    for (i = 0; i < size; ++i) {
        if (umap.find(candyType[i]) == umap.end()) {
            umap[candyType[i]] = 1;   // Assign value if doesn't exists.
        } else {
            umap[candyType[i]] += 1;  // Counter +1 if it exists.
        }
    }

    size = size / 2;

    return min(size, umap.size());
}

int Solution::scoreOfParentheses(std::string S)
{
    return 0;
}

int Solution::numPairsDivisibleBy60(std::vector<int>& time)
{
    std::vector<int> count(60, 0);
    size_t idx;
    int ret = 0;

    for (idx = 0; idx < time.size(); ++idx) {
        ++count[time[idx] % 60];
    }

    if (count[0] >= 2) {
        ret += count[0] * (count[0] - 1) / 2;
    }

    if (count[30] >= 2) {
        ret += count[30] * (count[30] - 1) / 2;
    }

    for (idx = 1; idx < 30; ++idx) {
        ret += count[idx] * count[60 - idx];
    }

    return ret;
}

/**
 * @score (runtime / memory) (73.22% / 67.30%)
 */
bool canVisitAllRooms(std::vector<std::vector<int> >& rooms)
{
    std::vector<bool> visited(rooms.size(), false);
    std::stack<int> frontier; /** Should replaced with a unique container */
    std::vector<int>::iterator iter, end;
    int room, max = rooms.size();

    visited[0] = true;
    for (iter = rooms[0].begin(), end = rooms[0].end(); iter != end; ++iter) {
        frontier.push(*iter);
    }

    while (!frontier.empty()) {
        room = frontier.top(); frontier.pop();

        if (visited[room]) {
            continue;
        }

        visited[room] = true;
        for (iter = rooms[room].begin(), end = rooms[room].end(); iter != end; ++iter) {
            frontier.push(*iter);
        }
    }

    for (room = 0; room < max; ++room) {
        if (!visited[room]) {
            return false;
        }
    }

    return true;
}

bool Solution::increasingTriplet(std::vector<int>& nums)
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

std::vector<int> Solution::sumZero(int n)
{
    std::vector<int> ret(n, 0);
    int tmp, i;

    tmp = 0;
    for (i = n / 2 - 1; i >= 0; --i) {
        ret[i] = ++tmp;
    }

    tmp = 0;
    i = (n % 2)? (n / 2 + 1) : (n / 2);
    for (; i < n; ++i) {
        ret[i] = --tmp;
    }

    return ret;
}

/**
 * @score (runtime / memory) (96.87% / 98.98%)
 */
std::vector<int> Solution::grayCode(int n)
{
    std::vector<int> seq(1 << n, 0);
    std::vector<int>::iterator ref, iter, target, end;
    int seg_size = (1 << 1);

    seq[0] = 0;
    seq[1] = 1;

    ref = seq.begin();
    end = seq.end();

    iter = seq.begin() + seg_size;
    while (iter != end) {
        std::reverse_copy(ref, ref + seg_size, iter);
        for (target = iter + seg_size; iter != target; ++iter) {
            *iter += seg_size;
        }
        seg_size <<= 1;
    }

    return seq;
}
/**
 * @time-complexity  O(N), N stands for the length of nums
 * @space-complexity O(N), N stands for the length of nums
 */
std::vector<int> findErrorNums(std::vector<int>& nums)
{
	int size = nums.size();

	std::vector<int> buf(size + 1, 1);
	std::vector<int> ans(2, 0);

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

std::vector<std::vector<int> > Solution::permute(std::vector<int>& nums)
{
    std::vector<std::vector<int> > permutations;

    return permutations;
}
