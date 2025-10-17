# Minimum-Swaps-to-Make-Strings-Equal

A C++ program to find the minimum number of swaps required to make two strings of 'x's and 'y's identical.

-----

## Problem

You are given two strings `s1` and `s2` of equal length, which consist of only the characters `'x'` and `'y'`. In one operation, you can choose any two indices `i` and `j` and swap `s1[i]` with `s2[j]`.

Return the minimum number of swaps required to make `s1` and `s2` the same, or `-1` if it is impossible.

-----

## Example

**Input:** `s1 = "xy"`, `s2 = "yx"`

**Explanation:**

  - We have an 'x'/'y' mismatch at index 0 and a 'y'/'x' mismatch at index 1.

<!-- end list -->

1.  Swap `s1[0]` ('x') with `s2[0]` ('y'). `s1` becomes "yy", `s2` becomes "xx".
2.  Swap `s1[0]` ('y') with `s2[1]` ('x'). `s1` becomes "xy", `s2` becomes "yx".
    This doesn't seem right. Let's try another swap.
3.  Swap `s1[1]` ('y') with `s2[1]` ('x'). `s1` becomes "xx", `s2` becomes "yy".
4.  Now, swap `s1[0]` ('x') with `s2[1]` ('y'). Both strings become "yx".
    This took 2 swaps.

**Output:** `2`

-----

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if (s1.length() != s2.length()) {
            return -1; // Should not happen based on problem description
        }

        int xy_mismatches = 0; // Count of mismatches where s1 has 'x' and s2 has 'y'
        int yx_mismatches = 0; // Count of mismatches where s1 has 'y' and s2 has 'x'

        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == 'x' && s2[i] == 'y') {
                xy_mismatches++;
            } else if (s1[i] == 'y' && s2[i] == 'x') {
                yx_mismatches++;
            }
        }

        // If the total number of mismatched 'x's (and 'y's) is odd, it's impossible.
        if ((xy_mismatches + yx_mismatches) % 2 != 0) {
            return -1;
        }

        // Two mismatches of the same type (e.g., two 'xy') can be fixed in one swap.
        int swaps = xy_mismatches / 2 + yx_mismatches / 2;

        // If one 'xy' and one 'yx' mismatch remain, they require two swaps to fix.
        if (xy_mismatches % 2 != 0) {
            swaps += 2;
        }

        return swaps;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    string s1 = "xy";
    string s2 = "yx";

    int result = sol.minimumSwap(s1, s2);
    cout << "Minimum swaps required for s1=\"" << s1 << "\", s2=\"" << s2 << "\": " << result << endl; // Output: 2

    string s3 = "xx";
    string s4 = "yy";
    result = sol.minimumSwap(s3, s4);
    cout << "Minimum swaps required for s1=\"" << s3 << "\", s2=\"" << s4 << "\": " << result << endl; // Output: 1

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(n)$, where `n` is the length of the strings. We iterate through the strings once to count mismatches.
  - **Space:** $O(1)$, as we only use a few integer variables for counting.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o min_swaps main.cpp`
  - **Run:** `./min_swaps`

-----

## Notes

  - The key to this problem is to count the two types of mismatches: `xy` (`s1[i] = 'x', s2[i] = 'y'`) and `yx` (`s1[i] = 'y', s2[i] = 'x'`).
  - **Case 1:** Two mismatches of the same type (e.g., two `xy` mismatches) can be resolved with a single swap. For `s1 = "xx"` and `s2 = "yy"`, swapping `s1[0]` with `s2[1]` makes both strings `"yx"`. This contributes `xy_mismatches / 2` to the total swaps.
  - **Case 2:** If after pairing up same-type mismatches, we are left with one `xy` mismatch and one `yx` mismatch, it takes two swaps to resolve them. This contributes `2` to the total swaps.
  - **Impossible Case:** For the strings to become equal, the total count of 'x's and 'y's must be even across both strings. This means the total number of mismatches (`xy_mismatches + yx_mismatches`) must be even. If it's odd, it's impossible to fix, so we return `-1`.
