350 Intersection-of-Two-Arrays-II
A C++ program to find the intersection of two integer arrays, allowing for duplicate elements.

## 📊 Difficulty Level

Easy

## 🔗 Problem Link

[LeetCode 350: Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/)

## 🏷️ Topic Tags

Array
Hash Table
Two Pointers
Sorting

## Problem

Given two integer arrays `nums1` and `nums2`, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays, and you may return the result in **any order**.

## Example

**Input:** `nums1 = [1, 2, 2, 1], nums2 = [2, 2]`
**Explanation:**

1.  Count frequencies in `nums2`: `{2: 2}`.
2.  Iterate through `nums1`:
      - `1`: Not in map. Skip.
      - `2`: In map (count 2). Add to result, decrement count to 1.
      - `2`: In map (count 1). Add to result, decrement count to 0.
      - `1`: Not in map. Skip.
        **Output:** `[2, 2]`

**Input:** `nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]`
**Output:** `[4, 9]`

## Code

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> f;
        
        // Step 1: Build a frequency map for the elements in nums2
        for(int n : nums2) {
            f[n]++;
        }
        
        vector<int> res;
        
        // Step 2: Iterate through nums1 and check against the map
        for(int n : nums1) {
            // If the element exists in map and has a count > 0
            if(f[n] > 0) {
                res.push_back(n); // Add to result
                f[n]--;           // Decrement frequency to handle duplicates
            }
        }
        
        return res;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> result = sol.intersect(nums1, nums2);

    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: 2 2

    return 0;
}
```

## Complexity

  * **Time:** $O(N + M)$, where $N$ and $M$ are the lengths of the arrays. We traverse `nums2` once to build the map and `nums1` once to check for intersections.
  * **Space:** $O(min(N, M))$. We store the frequency map of one array. (Note: To optimize space, it is better to build the map using the smaller array).

## Build & Run

  * **Compile:** `g++ -std=c++17 -O2 -o intersect_arrays main.cpp`
  * **Run:** `./intersect_arrays`

## Notes

  * **Handling Duplicates:** Unlike "Intersection of Two Arrays I" (which requires unique elements), this problem requires tracking frequencies using a Hash Map.
  * **Optimization:** If the arrays were already sorted, a **Two Pointer** approach could be used to solve this in $O(N + M)$ time and $O(1)$ extra space (ignoring the output array).
  * **Memory usage:** In the provided solution, we map `nums2`. If `nums2` is significantly larger than `nums1`, it is more memory efficient to swap them and map the smaller array instead.
