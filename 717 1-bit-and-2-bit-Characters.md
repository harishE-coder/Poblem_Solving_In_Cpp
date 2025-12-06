# 1-bit-and-2-bit-Characters

A C++ program to determine if the last character in a binary array is a one-bit character.

-----

## Problem

We have two special characters:

1.  The first character can be represented by one bit `0`.
2.  The second character can be represented by two bits (`10` or `11`).

Given a binary array `bits` that ends with `0`, return `true` if the last character must be a one-bit character.

-----

## Example

**Input:** `bits = [1, 0, 0]`

**Explanation:**

  - We start at index 0. `bits[0]` is `1`, so it must be the start of a 2-bit character (`10`).
  - We skip two bits and land at index 2.
  - `bits[2]` is `0`. Since we are at the last index, this must be a 1-bit character.

**Output:** `true`

**Input:** `bits = [1, 1, 1, 0]`

**Explanation:**

  - We start at index 0. `bits[0]` is `1`, so it's a 2-bit character (`11`). Jump to index 2.
  - `bits[2]` is `1`, so it's also a 2-bit character (`10`). Jump to index 4.
  - We have passed the last index (index 3). The last `0` was part of the second character, not a standalone 1-bit character.

**Output:** `false`

-----

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        
        // Iterate through the array, stopping BEFORE the last element
        while (i < n - 1) {
            // If the current bit is 1, it must be a 2-bit character (10 or 11).
            // Skip the next bit by advancing 2 steps.
            if (bits[i] == 1) {
                i += 2;
            } 
            // If the current bit is 0, it is a 1-bit character.
            // Advance 1 step.
            else {
                i++;
            }
        }
        
        // If 'i' lands exactly on the last index (n-1), it means the last character is 1-bit.
        // If 'i' exceeds n-1, the last bit was consumed by a 2-bit character.
        return i == n - 1;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    
    vector<int> bits1 = {1, 0, 0};
    cout << "Is last character 1-bit? " << (sol.isOneBitCharacter(bits1) ? "Yes" : "No") << endl; // Output: Yes

    vector<int> bits2 = {1, 1, 1, 0};
    cout << "Is last character 1-bit? " << (sol.isOneBitCharacter(bits2) ? "Yes" : "No") << endl; // Output: No

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(N)$, where `N` is the length of the `bits` array. In the worst case, we traverse the array once.
  - **Space:** $O(1)$, as we only use a single integer variable `i` to track our position.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o one_bit_char main.cpp`
  - **Run:** `./one_bit_char`

-----

## Notes

  - This is a **Greedy Algorithm**. Because the decoding is unambiguous (if you see a `1`, the next bit *must* be part of that character), we can simply simulate the parsing process from left to right.
  - The loop condition `i < n - 1` is crucial. It ensures we stop processing *before* we potentially consume the very last bit as the start of a new character.
  - If the loop finishes and `i` is exactly `n - 1`, it implies the last bit stands alone as a 1-bit character. If `i` becomes `n`, it means the last bit was part of a pair ending at `n - 1`.
