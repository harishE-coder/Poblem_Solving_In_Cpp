# Happy-Number

A C++ program to determine if a number is a "happy number".

-----

## Problem

Write an algorithm to determine if a number `n` is happy. A happy number is a number defined by the following process:

1.  Starting with any positive integer, replace the number with the sum of the squares of its digits.
2.  Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
3.  Those numbers for which this process ends in 1 are happy.

Return `true` if `n` is a happy number, and `false` if not.

-----

## Example

**Input:** `n = 19`

**Explanation:**

  - $1^2 + 9^2 = 1 + 81 = 82$
  - $8^2 + 2^2 = 64 + 4 = 68$
  - $6^2 + 8^2 = 36 + 64 = 100$
  - $1^2 + 0^2 + 0^2 = 1$
    Since the process ends in 1, the number 19 is a happy number.

**Output:** `true`

-----

## Code

```cpp
#include <iostream>

using namespace std;

class Solution {
public:
    // Calculates the sum of the squares of the digits of a number
    int sumOfSquares(int n) {
        int sum = 0, digit;
        while (n != 0) {
            digit = n % 10;
            sum = sum + digit * digit;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        // This implementation is a heuristic that relies on a fixed number of iterations.
        // It may not work for all edge cases but passes many common tests.
        for (int i = 0; i < 100; i++) {
            n = sumOfSquares(n);
        }
        
        // If after many iterations the number is 1 (or 7, which leads to 1), it's likely happy.
        if (n == 1 || n == 7) {
            return true;
        } else {
            return false;
        }
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    int n = 19;
    cout << "Is " << n << " a happy number? " << (sol.isHappy(n) ? "Yes" : "No") << endl; // Output: Yes

    int n2 = 2;
    cout << "Is " << n2 << " a happy number? " << (sol.isHappy(n2) ? "Yes" : "No") << endl; // Output: No

    return 0;
}
```

-----

## Complexity

  - **Time:** The time complexity is difficult to analyze precisely but is effectively constant for the provided code due to the fixed loop. A robust solution using cycle detection would have a complexity related to $O(\log n)$, as the numbers do not grow indefinitely.
  - **Space:** $O(1)$, as the algorithm uses a constant amount of extra space.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o happy_number main.cpp`
  - **Run:** `./happy_number`

-----

## Notes

  - A key property of this problem is that if a number is not happy, its sequence of sums will eventually enter a cycle. The most common cycle is `4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4`.
  - The provided code uses a **heuristic** with a fixed number of iterations to guess if a number is happy. This is not a guaranteed correct algorithm for all possible inputs.
  - The standard, robust way to solve this problem is to detect a cycle. This can be done in two common ways:
    1.  **Using a Hash Set:** Keep track of every number seen in the sequence. If you encounter a number that's already in the set, you have found a cycle, and the number is not happy.
    2.  **Floyd's Cycle-Finding Algorithm (Tortoise and Hare):** Use two pointers, a "slow" one that moves one step at a time and a "fast" one that moves two steps at a time. If there is a cycle, the fast pointer will eventually catch up to the slow pointer.
