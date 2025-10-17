# Jewels-and-Stones

A C++ program to count how many of your stones are also jewels.

-----

## Problem

You're given strings `jewels` representing the types of stones that are jewels, and `stones` representing the stones you have. Each character in `stones` is a type of stone you have. You want to know how many of the stones you have are also jewels.

The letters in `jewels` are guaranteed to be distinct, and all characters in `jewels` and `stones` are letters. The comparison is case-sensitive, so "a" is considered a different type of stone from "A".

-----

## Example

**Input:** `jewels = "aA"`, `stones = "aAAbbbb"`

**Explanation:**
The types of stones that are jewels are 'a' and 'A'. In the `stones` string, you have one 'a' and two 'A's. Therefore, you have 3 jewels in total.

**Output:** `3`

-----

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int cnt = 0;
        // For each type of jewel...
        for (char c : jewels) {
            // ...check every stone you have.
            for (char n : stones) {
                if (c == n) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    string jewels = "aA";
    string stones = "aAAbbbb";

    int result = sol.numJewelsInStones(jewels, stones);
    cout << "You have " << result << " jewels." << endl; // Output: 3

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(J \cdot S)$, where `J` is the length of `jewels` and `S` is the length of `stones`. This is because of the nested loops that compare every jewel against every stone.
  - **Space:** $O(1)$, as the algorithm only uses a single integer counter, requiring constant extra space.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o jewels_and_stones main.cpp`
  - **Run:** `./jewels_and_stones`

-----

## Notes

  - The provided code is a straightforward **brute-force** solution.
  - A more efficient approach would be to use a hash set (`std::unordered_set` in C++) to store the jewel types. This would improve the time complexity to $O(J + S)$.
    1.  Insert all characters from `jewels` into the hash set (takes $O(J)$ time).
    2.  Iterate through `stones`, and for each stone, check if it exists in the hash set (takes $O(S)$ time, as each lookup is $O(1)$ on average).
