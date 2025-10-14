# Reverse-Integer

A C++ program to reverse the digits of a 32-bit signed integer while handling potential overflow.

-----

## Problem

Given a 32-bit signed integer `x`, reverse its digits. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-2^31, 2^31 - 1]`, then return `0`. Assume the environment does not allow you to store 64-bit integers.

-----

## Example

**Input:** `x = -123`

**Explanation:**

1.  Extract the last digit: `3`. Result: `3`. `x` becomes `-12`.
2.  Extract the last digit: `2`. Result: `3 * 10 + 2 = 32`. `x` becomes `-1`.
3.  Extract the last digit: `1`. Result: `32 * 10 + 1 = 321`. `x` becomes `0`.
4.  Apply the original sign.

**Output:** `-321` (The sign is handled naturally by the modulo and division operations on a negative number).

-----

## Code

```cpp
#include <iostream>
#include <climits> // For INT_MAX and INT_MIN

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int reversed_num = 0;
        while (x != 0) {
            int last_digit = x % 10;

            // Check for overflow/underflow before multiplication
            if (reversed_num > INT_MAX / 10 || reversed_num < INT_MIN / 10) {
                return 0;
            }
            
            // A more precise check would also look at the last digit:
            // if (reversed_num > INT_MAX / 10 || (reversed_num == INT_MAX / 10 && last_digit > 7)) return 0;
            // if (reversed_num < INT_MIN / 10 || (reversed_num == INT_MIN / 10 && last_digit < -8)) return 0;

            reversed_num = reversed_num * 10 + last_digit;
            x /= 10;
        }
        return reversed_num;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    int num1 = 123;
    cout << "Reverse of " << num1 << " is: " << sol.reverse(num1) << endl; // Output: 321

    int num2 = -123;
    cout << "Reverse of " << num2 << " is: " << sol.reverse(num2) << endl; // Output: -321

    int num3 = 1534236469;
    cout << "Reverse of " << num3 << " is: " << sol.reverse(num3) << endl; // Output: 0 (overflow)

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(\log_{10}(x))$, as we process one digit of `x` in each iteration. The number of digits is proportional to the base-10 logarithm of `x`.
  - **Space:** $O(1)$, as we only use a few variables to store the result and intermediate values, regardless of the input size.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o reverse_integer main.cpp`
  - **Run:** `./reverse_integer`

-----

## Notes

  - The core of the algorithm is to repeatedly extract the last digit of `x` using the modulo operator (`% 10`) and build the reversed number by multiplying the current result by 10 and adding the extracted digit.
  - The most critical part is the **overflow check**. Before multiplying `reversed_num` by 10, we must ensure it won't exceed the 32-bit integer limits (`INT_MAX` or `INT_MIN`).
  - The check `reversed_num > INT_MAX / 10` is a clever way to detect impending overflow. If the current reversed number is already greater than what the maximum integer would be after dividing by 10, the next multiplication will surely cause an overflow. The same logic applies to `INT_MIN`.
