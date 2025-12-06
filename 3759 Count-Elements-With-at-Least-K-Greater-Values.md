3759 Count-Elements-With-at-Least-K-Greater-Values
A C++ program to count elements that have at least `k` strictly greater elements in the array.

## 📊 Difficulty Level

Medium

## 🔗 Problem Link

[LeetCode 3759: Count Elements With at Least K Greater Values](https://leetcode.com/problems/count-elements-with-at-least-k-greater-values/)

## 🏷️ Topic Tags

Array
Sorting
Binary Search

## Problem

Given an integer array `nums` and an integer `k`, return the number of elements in the array that have **at least** `k` elements strictly greater than them.

## Example

**Input:** `nums = [11, 7, 2, 15], k = 2`
**Explanation:**

1.  Sort the array: `[2, 7, 11, 15]`.
2.  Check each element:
      - **2**: Greater elements are `{7, 11, 15}` (3 elements). $3 \ge 2$. (Valid)
      - **7**: Greater elements are `{11, 15}` (2 elements). $2 \ge 2$. (Valid)
      - **11**: Greater element is `{15}` (1 element). $1 < 2$. (Invalid)
      - **15**: Greater elements `{}` (0 elements). $0 < 2$. (Invalid)
        **Output:** `2`

## Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return n;         // Every element has >= 0 elements greater
        if (k >= n) return 0;         // Impossible to have >= n elements greater

        // Step 1: Sort array to determine relative order
        // Time Complexity: O(N log N)
        sort(nums.begin(), nums.end());

        // Step 2: Determine the threshold
        // The element at index (n - k) is the smallest element that fails the condition.
        // Any element strictly smaller than nums[n - k] will satisfy the condition.
        int threshold = nums[n - k];

        // Step 3: Count elements strictly less than the threshold
        // lower_bound finds the first element that is >= threshold.
        // The index of this iterator corresponds to the count of elements strictly smaller.
        int cnt = lower_bound(nums.begin(), nums.end(), threshold) - nums.begin();
        
        return cnt;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums = {11, 7, 2, 15};
    int k = 2;

    int result = sol.countElements(nums, k);

    cout << "Count: " << result << endl; // Output: 2

    return 0;
}
```

## Complexity

  * **Time:** $O(N \log N)$, where $N$ is the length of the array. The dominant operation is sorting. Finding the count using `lower_bound` takes $O(\log N)$.
  * **Space:** $O(1)$ (ignoring the recursion stack space required by the sorting algorithm).

## Build & Run

  * **Compile:** `g++ -std=c++17 -O2 -o count_elements main.cpp`
  * **Run:** `./count_elements`

## Notes

  * **Logic:** In a sorted array, the element at index `n - k` has exactly `k - 1` elements at indices `n - k + 1` to `n - 1` that are greater than or equal to it.
  * **Strict Inequality:** Since the problem requires elements strictly greater, any number equal to `nums[n - k]` will not suffice if there are duplicates. Therefore, only numbers strictly smaller than `nums[n - k]` are counted.
  * **Edge Cases:** The code handles cases where `k=0` (all elements valid) and `k >= n` (no elements valid) immediately.

-----

Would you like me to prepare a similar formatted solution for another problem, or help you add this to your GitHub repository?
