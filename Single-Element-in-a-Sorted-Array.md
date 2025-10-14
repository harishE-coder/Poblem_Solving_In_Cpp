# Single-Element-in-a-Sorted-Array

A C++ program to find the single element that appears only once in a sorted array.

-----

## Problem

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element.

Your solution should run in $O(\log n)$ time and $O(1)$ space.

-----

## Example

**Input:** `nums = [1, 1, 2, 3, 3, 4, 4, 8, 8]`

**Explanation:**
All numbers appear twice, except for `2`.

**Output:** `2`

-----

## Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int single = 0;
        // The XOR sum of all elements will cancel out the pairs,
        // leaving only the single element.
        for (int n : nums) {
            single ^= n;
        }
        return single;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};

    int result = sol.singleNonDuplicate(nums);

    cout << "The single non-duplicate element is: " << result << endl; // Output: 2

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(n)$, where `n` is the number of elements in the array. We iterate through the array once.
  - **Space:** $O(1)$, as we only use a single integer variable for storage, regardless of the input size.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o single_non_duplicate main.cpp`
  - **Run:** `./single_non_duplicate`

-----

## Notes

  - This solution uses the bitwise **XOR** (`^`) operator. The key properties of XOR are:
      - `x ^ x = 0` (any number XORed with itself is zero).
      - `x ^ 0 = x` (any number XORed with zero is itself).
  - This approach is very elegant and works even if the array is **not sorted**.
  - However, because the problem specifies that the array is **sorted**, a more optimal solution using **binary search** can achieve a time complexity of $O(\log n)$, which is faster than this $O(n)$ solution.
