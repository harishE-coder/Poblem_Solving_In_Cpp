88 Merge-Sorted-Array
A C++ program to merge two sorted integer arrays into a single sorted array in-place.

## 📊 Difficulty Level

Easy

## 🔗 Problem Link

[LeetCode 88: Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)

## 🏷️ Topic Tags

Array
Two Pointers
Sorting

## Problem

You are given two integer arrays `nums1` and `nums2`, sorted in **non-decreasing order**, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.

Merge `nums1` and `nums2` into a single array sorted in **non-decreasing order**.

The final sorted array should not be returned by the function, but instead be stored inside the array `nums1`. To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored.

## Example

**Input:** `nums1 = [1, 2, 3, 0, 0, 0], m = 3`, `nums2 = [2, 5, 6], n = 3`
**Explanation:**

1.  Pointers: `i` at index 2 (val 3), `j` at index 2 (val 6), `k` at index 5.
2.  Compare `3` vs `6`: `6` is larger. Place `6` at `k`. Decrement `j`, `k`.
3.  Compare `3` vs `5`: `5` is larger. Place `5` at `k`. Decrement `j`, `k`.
4.  Compare `3` vs `2`: `3` is larger. Place `3` at `k`. Decrement `i`, `k`.
5.  Continue until merged.
    **Output:** `[1, 2, 2, 3, 5, 6]`

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // Pointer for the end of valid elements in nums1
        int j = n - 1;      // Pointer for the end of nums2
        int k = m + n - 1;  // Pointer for the end of the total size of nums1

        // Iterate backwards while both arrays have elements
        while(i >= 0 && j >= 0) {
            if(nums1[i] < nums2[j]) {
                nums1[k--] = nums2[j--]; // Place larger element at the end
            }
            else {
                nums1[k--] = nums1[i--];
            }
        }

        // If elements remain in nums2, copy them over
        // (No need to copy nums1, they are already in place)
        while(j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    sol.merge(nums1, m, nums2, n);

    cout << "Merged Array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl; // Output: 1 2 2 3 5 6

    return 0;
}
```

## Complexity

  * **Time:** $O(m + n)$. We iterate through both arrays at most once.
  * **Space:** $O(1)$. The merge is done in-place without using extra space for another array.

## Build & Run

  * **Compile:** `g++ -std=c++17 -O2 -o merge_sorted main.cpp`
  * **Run:** `./merge_sorted`

## Notes

  * **Reverse Iteration Strategy:** The key to solving this in $O(1)$ space is filling the array from the **back** (index `m + n - 1`).
  * If we started from the front, we would overwrite elements in `nums1` that haven't been processed yet.
  * **Edge Cases:**
      * `n = 0`: The second loop doesn't run, `nums1` remains unchanged (correct).
      * `m = 0`: The first loop doesn't run, the second loop copies all of `nums2` into `nums1` (correct).
