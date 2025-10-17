# Find-the-Pivot-Integer

A C++ program to find the pivot integer `x` such that the sum of elements from `1` to `x` equals the sum of elements from `x` to `n`.

-----

## Problem

Given a positive integer `n`, find the **pivot integer** `x` such that:

  - The sum of all numbers between `1` and `x` (inclusive) is equal to the sum of all numbers between `x` and `n` (inclusive).

Return the pivot integer `x`. If no such integer exists, return `-1`.

-----

## Example

**Input:** `n = 8`

**Explanation:**

  - The sum of numbers from 1 to 6 is `1 + 2 + 3 + 4 + 5 + 6 = 21`.
  - The sum of numbers from 6 to 8 is `6 + 7 + 8 = 21`.
  - Since the sums are equal, `6` is the pivot integer.

**Output:** `6`

-----

## Code

```cpp
#include <iostream>
#include <cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        // The sum of numbers from 1 to n is n * (n + 1) / 2
        int total_sum = n * (n + 1) / 2;
        
        // From the problem's condition, it can be derived that x*x = total_sum
        int x = sqrt(total_sum);
        
        // If x*x equals the total_sum, then 'x' is an integer and a valid pivot
        if (x * x == total_sum) {
            return x;
        }
        
        // Otherwise, no integer pivot exists
        return -1;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    int n = 8;
    int result = sol.pivotInteger(n);
    cout << "The pivot integer for n = " << n << " is: " << result << endl; // Output: 6

    n = 4;
    result = sol.pivotInteger(n);
    cout << "The pivot integer for n = " << n << " is: " << result << endl; // Output: -1

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(1)$, as the solution only involves a few arithmetic operations and a square root function, which are considered constant time.
  - **Space:** $O(1)$, because it uses a fixed amount of extra space regardless of the input `n`.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o pivot_integer main.cpp`
  - **Run:** `./pivot_integer`

-----

## Notes

  - This solution is based on a mathematical derivation. The condition is `sum(1..x) = sum(x..n)`.
  - This can be rewritten as `sum(1..x) = sum(1..n) - sum(1..x-1)`.
  - Using the sum formula `S(k) = k * (k+1) / 2`, the equation becomes:
    `x*(x+1)/2 = n*(n+1)/2 - (x-1)*x/2`
  - Solving this equation for `x` simplifies to `x^2 = n*(n+1)/2`.
  - This means a pivot `x` exists only if the total sum from `1` to `n` is a perfect square. The pivot is simply the square root of that sum.
