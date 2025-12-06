# Count-Total-Number-of-Colored-Cells

A C++ program to calculate the number of colored cells in a grid after `n` minutes of expansion.

-----

## Problem

There exists an infinitely large two-dimensional grid of uncolored unit cells. You are given a positive integer `n`.

  - Initially, at minute 1, one specific cell is colored blue.
  - Every minute thereafter, every uncolored cell that touches a blue cell (shares an edge) becomes blue.

Return the number of colored cells at the end of `n` minutes.

-----

## Example

**Input:** `n = 3`

**Explanation:**

  - **Minute 1:** 1 cell is colored.
  - **Minute 2:** The center cell touches 4 neighbors. Total = $1 + 4 = 5$.
  - **Minute 3:** The existing 5 cells touch 8 new neighbors. Total = $5 + 8 = 13$.

**Output:** `13`

-----

## Code

```cpp
#include <iostream>

using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        // The pattern grows as a sequence of centered square numbers.
        // Formula: 1 + 4 * (sum of integers from 1 to n-1)
        //        = 1 + 4 * ( (n-1) * n / 2 )
        //        = 1 + 2 * n * (n - 1)
        //        = 2 * n^2 - 2 * n + 1
        
        // Use 1LL to ensure the calculation is done in long long to prevent overflow
        return 1LL * (2LL * n * n - 2LL * n + 1);
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    int n = 3;
    cout << "Colored cells at minute " << n << ": " << sol.coloredCells(n) << endl; // Output: 13

    n = 4;
    cout << "Colored cells at minute " << n << ": " << sol.coloredCells(n) << endl; // Output: 25

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(1)$. The solution uses a direct mathematical formula, requiring a constant number of arithmetic operations regardless of the input size.
  - **Space:** $O(1)$. No extra space is used.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o colored_cells main.cpp`
  - **Run:** `./colored_cells`

-----

## Notes

  - This problem basically asks for the $n$-th **Centered Square Number**.
  - The growth pattern adds a multiple of 4 cells at each step:
      - $n=1$: $1$
      - $n=2$: $1 + 4 = 5$
      - $n=3$: $5 + 8 = 13$
      - $n=4$: $13 + 12 = 25$
  - This arithmetic progression sums up to the formula $2n^2 - 2n + 1$.
  - Using `1LL` or explicit casting to `long long` is important because `n` can be large enough that `n*n` might overflow a standard 32-bit `int`.
