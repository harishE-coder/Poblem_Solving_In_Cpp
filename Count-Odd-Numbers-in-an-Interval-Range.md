# Count-Odd-Numbers-in-an-Interval-Range

A C++ program to count the number of odd integers within a given inclusive range.

-----

## Problem

Given two non-negative integers `low` and `high`, return the count of odd numbers between `low` and `high` (inclusive).

-----

## Example

**Input:** `low = 3`, `high = 7`

**Explanation:**
The odd numbers between 3 and 7 are 3, 5, and 7.

**Output:** `3`

-----

## Code

```cpp
#include <iostream>

using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        int count;

        // If both endpoints are even, the number of odds is exactly half the range length.
        if (low % 2 == 0 && high % 2 == 0) {
            count = (high - low) / 2;
        } 
        // If at least one endpoint is odd, there's one extra odd number.
        else {
            count = (high - low) / 2 + 1;
        }

        return count;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    int low = 3;
    int high = 7;

    int result = sol.countOdds(low, high);

    cout << "Number of odd numbers between " << low << " and " << high << " is: " << result << endl; // Output: 3

    int low2 = 8;
    int high2 = 10;
    result = sol.countOdds(low2, high2);
    cout << "Number of odd numbers between " << low2 << " and " << high2 << " is: " << result << endl; // Output: 1 (only 9)

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(1)$. The solution involves a few arithmetic operations, which take constant time.
  - **Space:** $O(1)$. No extra space is used that scales with the input.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o count_odds main.cpp`
  - **Run:** `./count_odds`

-----

## Notes

  - This solution leverages the properties of integer division to efficiently calculate the count without iterating through the range.
  - The logic distinguishes between two cases:
    1.  **Both `low` and `high` are even:** The number of odd integers is simply half the length of the interval. For example, in `[8, 10]`, the length is 2, and there is `2 / 2 = 1` odd number (9).
    2.  **At least one endpoint is odd:** In this case, the number of odd integers is half the length of the interval plus one. For example, in `[3, 7]`, the length is 4. The count is `4 / 2 + 1 = 3`.
  - A more concise mathematical approach is to calculate `(high + 1) / 2 - low / 2`. This formula computes the count of odd numbers up to `high` and subtracts the count of odd numbers up to `low - 1`.
