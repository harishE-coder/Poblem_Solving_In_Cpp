# 136 Single-Number

A C++ program to find the single element in an array where every other element appears twice.

-----

## 📊 Difficulty Level

**Easy**

## 🔗 Problem Link

[LeetCode 136: Single Number](https://leetcode.com/problems/single-number/)

## 🏷️ Topic Tags

  - Array
  - Bit Manipulation

-----

## Problem

Given a **non-empty** array of integers `nums`, every element appears *twice* except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

-----

## Example

**Input:** `nums = [4, 1, 2, 1, 2]`

**Explanation:**

  - `4` appears 1 time.
  - `1` appears 2 times.
  - `2` appears 2 times.
    The single element is `4`.

**Output:** `4`

-----

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        // XOR all elements together
        for (int n : nums) {
            res ^= n;
        }
        return res;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums = {4, 1, 2, 1, 2};

    int result = sol.singleNumber(nums);

    cout << "The single number is: " << result << endl; // Output: 4

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(n)$, where `n` is the number of elements in the array. We iterate through the list exactly once.
  - **Space:** $O(1)$. We use only a single variable `res` to store the result, regardless of the input size.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o single_number main.cpp`
  - **Run:** `./single_number`

-----

## Notes

  - This solution relies on the properties of the **XOR** (exclusive OR) bitwise operation:
    1.  $a \oplus 0 = a$ (Identity)
    2.  $a \oplus a = 0$ (Self-inverse)
    3.  $a \oplus b \oplus a = (a \oplus a) \oplus b = 0 \oplus b = b$ (Commutative and Associative)
  - Because every number appears twice except for one, all the pairs cancel each other out ($x \oplus x = 0$), leaving only the unique number in the result.
