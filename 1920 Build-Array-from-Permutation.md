# 1920 Build-Array-from-Permutation

A C++ program to build an array based on a specific permutation rule.

-----

## 📊 Difficulty Level

**Easy**

## 🔗 Problem Link

[LeetCode 1920: Build Array from Permutation](https://leetcode.com/problems/build-array-from-permutation/)

## 🏷️ Topic Tags

  - Array
  - Simulation

-----

## Problem

Given a **zero-based permutation** `nums` (0-indexed), build an array `ans` of the same length where `ans[i] = nums[nums[i]]` for each `0 <= i < nums.length` and return it.

A **zero-based permutation** `nums` is an array of distinct integers from `0` to `nums.length - 1` (inclusive).

-----

## Example

**Input:** `nums = [0, 2, 1, 5, 3, 4]`

**Explanation:**
The array is built as follows:

  - `ans[0] = nums[nums[0]] = nums[0] = 0`
  - `ans[1] = nums[nums[1]] = nums[2] = 1`
  - `ans[2] = nums[nums[2]] = nums[1] = 2`
  - `ans[3] = nums[nums[3]] = nums[5] = 4`
  - `ans[4] = nums[nums[4]] = nums[3] = 5`
  - `ans[5] = nums[nums[5]] = nums[4] = 3`

**Output:** `[0, 1, 2, 4, 5, 3]`

-----

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> res;
        // Simple direct mapping: res[i] gets the value at index nums[i]
        for (int i = 0; i < nums.size(); i++) {
            res.push_back(nums[nums[i]]);
        }
        return res;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums = {0, 2, 1, 5, 3, 4};

    vector<int> result = sol.buildArray(nums);

    cout << "Resulting Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: 0 1 2 4 5 3

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(n)$, where `n` is the length of the array. We iterate through the array exactly once.
  - **Space:** $O(n)$, since we create a new vector `res` to store the result.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o build_array main.cpp`
  - **Run:** `./build_array`

-----

## Notes

  - This solution uses **$O(n)$ extra space** to store the result, which is the most intuitive approach.
  - **Advanced Optimization:** It is possible to solve this in **$O(1)$ extra space** by encoding two numbers into one index. Since the numbers are within the range `[0, n-1]`, we can store both the old value and the new value at the same index using the formula: `nums[i] = nums[i] + (nums[nums[i]] % n) * n`. The new value can then be retrieved by dividing by `n`.
