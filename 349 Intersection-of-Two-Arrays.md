349 Intersection-of-Two-Arrays
A C++ program to find the unique intersection of two integer arrays.

## 📊 Difficulty Level

Easy

## 🔗 Problem Link

[LeetCode 349: Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/)

## 🏷️ Topic Tags

Array
Hash Table
Two Pointers

## Problem

Given two integer arrays `nums1` and `nums2`, return an array of their intersection. Each element in the result must be **unique** and you may return the result in **any order**.

## Example

**Input:** `nums1 = [1, 2, 2, 1], nums2 = [2, 2]`
**Explanation:**

1.  Unique elements in `nums2`: `{2}`.
2.  Iterate `nums1`:
      - `1`: Not in set.
      - `2`: In set. Add to result set `{2}`.
      - `2`: In set. Add to result set `{2}` (duplicate ignored).
      - `1`: Not in set.
3.  Result: `[2]`.
    **Output:** `[2]`

**Input:** `nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]`
**Output:** `[9, 4]` (or `[4, 9]`)

[Image of Venn diagram showing intersection of two sets]

## Code

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Step 1: Insert all elements of nums2 into a set for O(1) lookups
        unordered_set<int> s(nums2.begin(), nums2.end());
        
        // Step 2: Use another set to store the intersection to ensure uniqueness
        unordered_set<int> intersectionSet;
        
        for(int n : nums1) {
            // If the element from nums1 exists in nums2's set
            if(s.count(n)) {
                intersectionSet.insert(n);
            }
        }
        
        // Step 3: Convert the result set back to a vector
        vector<int> res(intersectionSet.begin(), intersectionSet.end());
        return res;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};

    vector<int> result = sol.intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: 9 4

    return 0;
}
```

## Complexity

  * **Time:** $O(N + M)$, where $N$ and $M$ are the lengths of the arrays. We iterate through both arrays once. Insertions and lookups in an unordered\_set are $O(1)$ on average.
  * **Space:** $O(N + M)$ in the worst case to store the sets for both arrays (if all elements are unique).

## Build & Run

  * **Compile:** `g++ -std=c++17 -O2 -o intersection_unique main.cpp`
  * **Run:** `./intersection_unique`

## Notes

  * **Uniqueness:** The key difference between this problem and "Intersection of Two Arrays II" is that the result here must contain unique elements only.
  * **Sets:** `std::unordered_set` is the perfect data structure here because it automatically handles duplicates and provides fast lookups.
  * **Optimization:** To minimize space, you can construct the initial set using the smaller of the two input arrays.
