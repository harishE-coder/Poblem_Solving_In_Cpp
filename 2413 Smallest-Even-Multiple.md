# Smallest-Even-Multiple

A C++ program to find the smallest positive integer that is a multiple of both 2 and a given number `n`.

-----

## LeetCode Problem Number

**2413**

-----

## Problem

Given a positive integer `n`, return the smallest positive integer that is a multiple of both `2` and `n`.

-----

## Example

**Input:** `n = 5`

**Explanation:**
The smallest multiple of both 5 and 2 is 10.

**Output:** `10`

**Input:** `n = 6`

**Explanation:**
The smallest multiple of both 6 and 2 is 6. Note that a number is a multiple of itself.

**Output:** `6`

-----

## Code

```cpp
#include <iostream>

using namespace std;

class Solution {
public:
    int smallestEvenMultiple(int n) {
        // If n is already even, the smallest multiple of both 2 and n is n itself.
        if (n % 2 == 0) {
            return n;
        }
        // If n is odd, the smallest multiple of both 2 and n is n * 2.
        else {
            return n * 2;
        }
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    int n = 5;
    cout << "Smallest even multiple of " << n << " is: " << sol.smallestEvenMultiple(n) << endl; // Output: 10

    n = 6;
    cout << "Smallest even multiple of " << n << " is: " << sol.smallestEvenMultiple(n) << endl; // Output: 6

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(1)$. The solution involves a simple modulo check and multiplication, which are constant time operations.
  - **Space:** $O(1)$. No extra space is used.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o smallest_even main.cpp`
  - **Run:** `./smallest_even`

-----

## Notes

  - This problem is essentially finding the **Least Common Multiple (LCM)** of `n` and `2`.
  - Since `2` is a prime number:
      - If `n` is divisible by `2` (even), then LCM(n, 2) = `n`.
      - If `n` is not divisible by `2` (odd), then LCM(n, 2) = `n * 2`.
  - A more concise one-liner solution using bitwise operations is `return n << (n & 1);`, but the current `if-else` logic is clearer to read.
