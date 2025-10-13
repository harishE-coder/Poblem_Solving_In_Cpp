

-----

# Bitwise-OR-of-Even-Numbers

A C++ program to compute the bitwise OR of all even numbers in an array.

## Problem

Given an array of integers, find the result of performing a bitwise OR operation on all the even numbers present in the array. If there are no even numbers, the result should be 0.

## Example

**Input:** `nums = [1, 2, 4, 7, 10]`

**Explanation:**
The even numbers in the array are `2`, `4`, and `10`.
The bitwise OR operation proceeds as follows:

  - Start with `0`.
  - `0 | 2` = `2` (Binary: `0000 | 0010` = `0010`)
  - `2 | 4` = `6` (Binary: `0010 | 0100` = `0110`)
  - `6 | 10` = `14` (Binary: `0110 | 1010` = `1110`)

**Output:** `14`

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int result = 0;
        for (int n : nums) {
            // Check if the number is even
            if (n % 2 == 0) {
                // Accumulate the bitwise OR
                result |= n;
            }
        }
        return result;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 4, 7, 10};

    int result = sol.evenNumberBitwiseORs(nums);

    cout << "The bitwise OR of all even numbers is: " << result << endl; // Output: 14

    return 0;
}
```

## Complexity

  - **Time:** $O(n)$, where `n` is the number of elements in the input array. We iterate through the array once.
  - **Space:** $O(1)$, as we only use a single integer variable (`result`) to store the accumulated value, regardless of the input size.

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o even_or main.cpp`
  - **Run:** `./even_or`

## Notes

  - The core of the solution is the bitwise OR assignment operator (`|=`), which combines the bits of the current even number with the accumulated result.
  - An alternative way to check for an even number is using the bitwise AND operator: `if ((n & 1) == 0)`. This checks if the least significant bit is 0, which is true for all even numbers.
  - The initial value of the accumulator is `0`. Performing a bitwise OR with `0` does not change the other operand (i.e., `x | 0 = x`), making it a perfect identity element for this operation.
