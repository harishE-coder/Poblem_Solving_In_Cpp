# Median-of-Two-Sorted-Arrays

A C++ program to find the median of two sorted arrays.

-----

## Problem

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return the median of the two sorted arrays. The overall run time complexity should be better than merging and sorting.

The **median** is the middle value in an ordered list of numbers. If the list has an even number of values, the median is the average of the two middle values.

-----

## Example

**Input:** `nums1 = [1, 2]`, `nums2 = [3, 4]`

**Explanation:**

1.  Merge the two arrays: `[1, 2, 3, 4]`
2.  The total number of elements is 4 (even).
3.  The two middle elements are `2` and `3`.
4.  The median is the average of these two: `(2 + 3) / 2.0 = 2.5`

**Output:** `2.5`

-----

## Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Insert elements of nums2 into the beginning of nums1
        nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
        
        // Sort the merged array
        sort(nums1.begin(), nums1.end());
        
        int n = nums1.size();
        int mid = n / 2;
        
        // Check if the total count is even or odd
        if (n % 2 == 0) {
            // Even: return the average of the two middle elements
            return (nums1[mid - 1] + nums1[mid]) / 2.0;
        } else {
            // Odd: return the single middle element
            return nums1[mid];
        }
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    double result = sol.findMedianSortedArrays(nums1, nums2);

    cout << "The median is: " << result << endl; // Output: 2.5

    // Note: The original nums1 is modified by the function call.
    // If you need to test again, re-initialize the vectors.
    vector<int> nums3 = {1, 3};
    vector<int> nums4 = {2};
    Solution sol2;
    result = sol2.findMedianSortedArrays(nums3, nums4);
    cout << "The median is: " << result << endl; // Output: 2.0

    return 0;
}
```

-----

## Complexity

  - **Time:** $O((m+n) \log(m+n))$, where `m` and `n` are the sizes of the two arrays. The dominant operations are inserting `n` elements into the first vector ($O(m+n)$) and then sorting the combined vector of size `m+n`.
  - **Space:** $O(1)$ if we consider the modification of `nums1` to be in-place, but it's more accurate to say $O(m+n)$ because the `nums1` vector has to be reallocated to hold all elements.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o median_of_arrays main.cpp`
  - **Run:** `./median_of_arrays`

-----

## Notes

  - This solution provides a correct answer but is **not optimal**. It is a brute-force approach that first merges the two arrays and then sorts them.
  - The problem on platforms like LeetCode typically expects a solution with a time complexity of $O(\log(\min(m, n)))$, which can be achieved using a **binary search** approach on the smaller array to find the correct partition point.
  - This implementation modifies one of the input vectors (`nums1`). In a real-world scenario, it's often better to create a new vector to hold the merged result to avoid side effects.
