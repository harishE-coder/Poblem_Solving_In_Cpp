2154 Keep Multiplying Found Values by Two
A C++ program to repeatedly multiply a number by two as long as the current value exists in the array.

## 📊 Difficulty Level

Easy

## 🔗 Problem Link

[LeetCode 2154: Keep Multiplying Found Values by Two](https://leetcode.com/problems/keep-multiplying-found-values-by-two/)

## 🏷️ Topic Tags

Array
Hash Table
Simulation
Sorting

## Problem

You are given an array of integers `nums` and an integer `original`. You need to perform the following steps:

1.  Search for `original` in `nums`.
2.  If `original` is found, multiply it by two (i.e., set `original = 2 * original`).
3.  Otherwise, stop the process.
4.  Repeat this process with the new number as long as you keep finding the number.

Return the **final** value of `original`.

## Example

**Input:** `nums = [5, 3, 6, 1, 12], original = 3`
**Explanation:**

1.  `3` is in `nums`. `original` becomes `3 * 2 = 6`.
2.  `6` is in `nums`. `original` becomes `6 * 2 = 12`.
3.  `12` is in `nums`. `original` becomes `12 * 2 = 24`.
4.  `24` is not in `nums`. Process stops.
    **Output:** `24`

**Input:** `nums = [2, 7, 9], original = 4`
**Explanation:**

1.  `4` is not in `nums`.
    **Output:** `4`

## Code

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        // Create a hash set for O(1) average time complexity lookups
        unordered_set<int> set(nums.begin(), nums.end());
        
        // Loop as long as the current 'original' exists in the set
        while(set.count(original)) {
            original *= 2;
        }
        
        return original;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums = {5, 3, 6, 1, 12};
    int original = 3;

    int result = sol.findFinalValue(nums, original);

    cout << "Final Value: " << result << endl; // Output: 24

    return 0;
}
```

## Complexity

  * **Time:** $O(N)$, where $N$ is the length of `nums`. creating the `unordered_set` takes $O(N)$. The `while` loop runs very few times because `original` grows exponentially ($2^k$), quickly exceeding the maximum possible integer value (or the maximum value in `nums`). Thus, the loop effectively takes constant time $O(1)$.
  * **Space:** $O(N)$ to store the elements of `nums` in the `unordered_set`.

## Build & Run

  * **Compile:** `g++ -std=c++17 -O2 -o find_final_value main.cpp`
  * **Run:** `./find_final_value`

## Notes

  * **Optimization:** Using a Hash Set (`unordered_set`) is efficient for lookups ($O(1)$).
  * **Alternative:** If we could not use extra space, we would have to sort the array ($O(N \log N)$) or scan the array repeatedly ($O(N^2)$), making the Hash Set approach the optimal time-space tradeoff for unsorted inputs.
  * **Constraints:** Since `original` doubles, it grows very fast. Even with large inputs, the loop will terminate quickly.
