**643 Maximum Average Subarray I**

A C++ program to find the contiguous subarray of length `k` that has the maximum average value.

## 📊 Difficulty Level

Easy

## 🔗 Problem Link

[LeetCode 643: Maximum Average Subarray I](https://leetcode.com/problems/maximum-average-subarray-i/)

## 🏷️ Topic Tags

Array
Sliding Window

## Problem

You are given an integer array `nums` consisting of `n` elements, and an integer `k`.

Find a contiguous subarray whose length is equal to `k` that has the maximum average value and return this value. Any answer with a calculation error less than $10^{-5}$ will be accepted.

## Example

**Input:** `nums = [1, 12, -5, -6, 50, 3], k = 4`
**Explanation:**

1.  Window 1 `[1, 12, -5, -6]`: Sum = 2. Average = 0.5.
2.  Window 2 `[12, -5, -6, 50]`: Sum = 51. Average = 12.75.
3.  Window 3 `[-5, -6, 50, 3]`: Sum = 42. Average = 10.5.
    The maximum average is 12.75.
    **Output:** `12.75000`

**Input:** `nums = [5], k = 1`
**Output:** `5.00000`

## Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For max

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;

        // Step 1: Calculate the sum of the first 'k' elements (initial window)
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }

        double maxSum = sum;

        // Step 2: Slide the window across the rest of the array
        for(int i = k; i < nums.size(); i++){
            sum += nums[i];      // Add the new element entering the window
            sum -= nums[i - k];  // Remove the old element leaving the window
            maxSum = max(maxSum, sum); // Update max sum if current window is larger
        }

        // Return average
        return maxSum / k;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;

    double result = sol.findMaxAverage(nums, k);

    cout << "Maximum Average: " << result << endl; // Output: 12.75

    return 0;
}
```

## Complexity

  * **Time:** $O(N)$, where $N$ is the length of `nums`. We iterate through the array exactly once.
  * **Space:** $O(1)$. We only use a few variables to store the sum and maximum.

## Build & Run

  * **Compile:** `g++ -std=c++17 -O2 -o max_average main.cpp`
  * **Run:** `./max_average`

## Notes

  * **Sliding Window:** This problem is a classic example of the **Sliding Window** technique. Instead of recalculating the sum for every subarray (which would be $O(N \cdot k)$), we update the sum in $O(1)$ by adding the incoming element and subtracting the outgoing element.
  * **Data Types:** Using `double` for the sum prevents integer overflow if the sum of `k` elements exceeds the integer limit, although standard constraints usually fit in `long long`. It also ensures the final division returns a floating-point result.
