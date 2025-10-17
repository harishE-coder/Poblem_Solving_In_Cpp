# Reverse-String

A C++ program to reverse a string in-place.

-----

## Problem

Write a function that reverses a string. The input string is given as an array of characters `s`. You must do this by modifying the input array **in-place** with $O(1)$ extra memory.

-----

## Example

**Input:** `s = ['h', 'e', 'l', 'l', 'o']`

**Explanation:**
After reversing the vector in-place, the elements are in the opposite order.

**Output:** `['o', 'l', 'l', 'e', 'h']`

-----

## Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        // Use the standard library's reverse function for an efficient in-place reversal.
        reverse(s.begin(), s.end());
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    cout << "Original string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    sol.reverseString(s);

    cout << "Reversed string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl; // Output: olleh

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(n)$, where `n` is the number of characters in the vector. The `std::reverse` algorithm makes approximately `n/2` swaps.
  - **Space:** $O(1)$, as the reversal is done in-place, using a constant amount of extra memory.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o reverse_string main.cpp`
  - **Run:** `./reverse_string`

-----

## Notes

  - This solution leverages the C++ Standard Library function `std::reverse`, which is the most concise and often the most efficient way to reverse a container.
  - A manual implementation of this would typically use a **two-pointer** approach. One pointer starts at the beginning of the vector and the other at the end. The characters at these pointers are swapped, and the pointers are moved towards the center until they meet or cross.
