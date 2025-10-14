# Maximum-Number-of-Balls-in-a-Box

A C++ program to find the box with the most balls, where the box number is determined by the sum of a ball's digits.

-----

## Problem

You're running a charity drive with an infinite number of boxes numbered from 1 upwards. You are given a range of balls, from `lowLimit` to `highLimit`. You place each ball into a box based on the sum of its digits. For example, a ball with the number `321` will be placed in box `3 + 2 + 1 = 6`.

Your task is to determine the maximum number of balls found in any single box after placing all the balls.

-----

## Example

**Input:** `lowLimit = 1`, `highLimit = 10`

**Explanation:**

  - Ball `1` goes into Box `1`.
  - Ball `2` goes into Box `2`.
  - ...
  - Ball `9` goes into Box `9`.
  - Ball `10` goes into Box `1 + 0 = 1`.

The counts for each box are:

  - Box `1`: 2 balls (`1`, `10`)
  - Box `2`: 1 ball (`2`)
  - ...
  - Box `9`: 1 ball (`9`)

The maximum number of balls in a single box is 2.

**Output:** `2`

-----

## Code

```cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        // Max sum of digits for a number up to 10^5 is 9+9+9+9+9 = 45.
        // A size of 50 is safe.
        vector<int> counts(50, 0);
        int maxBalls = 0;

        for (int num = lowLimit; num <= highLimit; num++) {
            int sum = 0, x = num;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            counts[sum]++;
            maxBalls = max(maxBalls, counts[sum]);
        }
        return maxBalls;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    int lowLimit = 1;
    int highLimit = 10;

    int result = sol.countBalls(lowLimit, highLimit);

    cout << "The maximum number of balls in any box is: " << result << endl; // Output: 2

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(N \cdot \log_{10}(M))$, where $N$ is the number of balls (`highLimit - lowLimit + 1`) and $M$ is the `highLimit`. For each of the $N$ balls, we perform an operation proportional to the number of its digits.
  - **Space:** $O(1)$, because the `counts` array has a fixed size. The maximum possible sum of digits for typical constraints (e.g., numbers up to $10^5$) is small and constant (45 for $99,999$).

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o count_balls main.cpp`
  - **Run:** `./count_balls`

-----

## Notes

  - The core of the problem is calculating the sum of digits for each number in the given range.
  - An array (or hash map) is used to keep track of the ball count for each box number (digit sum).
  - The size of the `counts` array is determined by the maximum possible sum of digits based on the problem's constraints on `highLimit`. For a `highLimit` up to $10^5$, the max sum is for $99,999$, which is $9 \times 5 = 45$. A size of 50 is sufficient.
