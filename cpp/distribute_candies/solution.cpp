#include "solution.h"

#include <iostream>
#include <unordered_map>

using namespace std;

inline int min(int a, int b)
{
    return (a > b)? b: a;
}

/**
 * @brief Learning how to use unordered_map / hashset (TODO)
 * @score (runtime / memory) (89.92% / 55.69%)
 * @time-complexity O(N). N stand for the length of input vector.
 * @notes Operation read / write / find in unordered_map is O(1)
 */
int Solution::distributeCandies(vector<int>& candyType) 
{
    unordered_map<int, int> umap;
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
