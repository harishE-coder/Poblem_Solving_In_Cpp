2441 Largest Positive Integer That Exists With Its Negative

A C++ program to find the largest positive integer $k$ such that $-k$ also exists in the array.

## 📊 Difficulty Level

Easy

## 🔗 Problem Link

[LeetCode 2441: Largest Positive Integer That Exists With Its Negative](https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/)

## 🏷️ Topic Tags

Array
Two Pointers
Sorting

## Problem

Given an integer array `nums` that does not contain any zeros, find the largest positive integer `k` such that `-k` also exists in the array.
Return the positive integer `k`. If there is no such integer, return `-1`.

## Example

**Input:** `nums = [-1, 2, -3, 3]`
**Explanation:**
The numbers in the array are `[-1, 2, -3, 3]`.

  - 3 is a positive integer and -3 is also in the array.
  - 2 is a positive integer but -2 is not in the array.
    The largest such positive integer is 3.
    **Output:** `3`

## Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // Required for sort

using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        // Sort the array to use Two Pointer technique effectively
        sort(nums.begin(), nums.end());
        
        while(left < right){
            int sum = nums[left] + nums[right];
            
            if (sum == 0) {
                // Found the pair (-k, k), return the positive value
                return nums[right];
            } 
            else if (sum < 0) {
                // Negative value is larger in magnitude, move left pointer forward
                left++;
            } 
            else {
                // Positive value is larger, move right pointer backward
                right--;
            }
        }
        return -1;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums = {-1, 10, 6, 7, -7, 1};

    int result = sol.findMaxK(nums);

    cout << "Largest K: " << result << endl; // Output: 7

    return 0;
}
```

## Complexity

  * **Time:** $O(N \log N)$, where $N$ is the length of the array. The dominant operation is sorting the array. The two-pointer traversal takes $O(N)$.
  * **Space:** $O(1)$ (ignoring the space required for sorting recursion stack, which is typically $O(\log N)$). We do not use any explicit extra data structures.

## Build & Run

  * **Compile:** `g++ -std=c++17 -O2 -o find_max_k main.cpp`
  * **Run:** `./find_max_k`

## Notes

  * This solution relies on the **Two Pointer** technique combined with sorting. Sorting places negative numbers at the start and positive numbers at the end, allowing efficient matching.
  * **Alternative Approach:** It is possible to solve this in $O(N)$ time using a **Hash Set** (specifically `std::unordered_set`) to store seen numbers, but that would increase the space complexity to $O(N)$. The sorting approach trades time for better space efficiency.

-----

Would you like the Hash Set ($O(N)$ time) version formatted this way as well?
