**1343 Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold**

A C++ program to count subarrays of a fixed size `k` whose average value meets a specific threshold.

## 📊 Difficulty Level

Medium

## 🔗 Problem Link

[LeetCode 1343: Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold](https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/)

## 🏷️ Topic Tags

Array
Sliding Window

## Problem

Given an array of integers `arr` and two integers `k` and `threshold`, return the number of sub-arrays of size `k` and average greater than or equal to `threshold`.

## Example

**Input:** `arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4`
**Explanation:**
The threshold for the sum is `threshold * k = 4 * 3 = 12`.

1.  `[2,2,2]`: Sum = 6. (6 \< 12) ❌
2.  `[2,2,2]`: Sum = 6. (6 \< 12) ❌
3.  `[2,2,5]`: Sum = 9. (9 \< 12) ❌
4.  `[2,5,5]`: Sum = 12. (12 \>= 12) ✅ (Count: 1)
5.  `[5,5,5]`: Sum = 15. (15 \>= 12) ✅ (Count: 2)
6.  `[5,5,8]`: Sum = 18. (18 \>= 12) ✅ (Count: 3)
    **Output:** `3`

**Input:** `arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5`
**Output:** `6`

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        
        // Step 1: Calculate sum of the first window of size k
        for(int i = 0; i < k; i++) sum += arr[i];
        
        int cnt = 0;
        
        // Optimization: Instead of calculating average (sum/k >= threshold),
        // we multiply threshold by k (sum >= threshold * k) to avoid float division.
        int targetSum = threshold * k;
        
        // Check the first window
        if(sum >= targetSum) cnt++;
        
        // Step 2: Slide the window
        for(int i = k; i < arr.size(); i++) {
            sum += arr[i];      // Add new element
            sum -= arr[i - k];  // Remove old element
            
            if(sum >= targetSum) cnt++;
        }
        
        return cnt;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> arr = {2, 2, 2, 2, 5, 5, 5, 8};
    int k = 3;
    int threshold = 4;

    int result = sol.numOfSubarrays(arr, k, threshold);

    cout << "Count: " << result << endl; // Output: 3

    return 0;
}
```

## Complexity

  * **Time:** $O(N)$, where $N$ is the length of `arr`. We traverse the array once.
  * **Space:** $O(1)$. We use constant extra space for variables.

## Build & Run

  * **Compile:** `g++ -std=c++17 -O2 -o num_subarrays main.cpp`
  * **Run:** `./num_subarrays`

## Notes

  * **Mathematical Optimization:** The condition `average >= threshold` is equivalent to `sum / k >= threshold`. To avoid slow floating-point division and potential precision issues, we rewrite this as `sum >= threshold * k`.
  * **Sliding Window:** This problem uses the fixed-size sliding window pattern. We update the sum in constant time $O(1)$ by adding the incoming element and subtracting the outgoing element.
