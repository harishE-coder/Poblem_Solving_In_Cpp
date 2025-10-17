# Isomorphic-Strings

A C++ program to determine if two strings are isomorphic.

-----

## Problem

Given two strings `s` and `t`, determine if they are isomorphic. Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

-----

## Example

**Input:** `s = "egg"`, `t = "add"`

**Explanation:**
The mapping is `e -> a`, `g -> d`. This mapping is consistent and one-to-one.

**Output:** `true`

**Input:** `s = "foo"`, `t = "bar"`

**Explanation:**
The mapping would need to be `f -> b`, `o -> a`, and `o -> r`. Since 'o' cannot map to two different characters ('a' and 'r'), the strings are not isomorphic.

**Output:** `false`

-----

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Helper function to generate a canonical pattern for a string
    string getPattern(const string& str) {
        unordered_map<char, int> ump;
        string pattern = "";
        int code = 0;
        for (char c : str) {
            // If the character is seen for the first time, assign it a new code
            if (ump.find(c) == ump.end()) {
                ump[c] = code++;
            }
            pattern += to_string(ump[c]) + " ";
        }
        return pattern;
    }

    bool isIsomorphic(string s, string t) {
        // Two strings are isomorphic if they have the same canonical pattern
        return getPattern(s) == getPattern(t);
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    string s1 = "egg";
    string t1 = "add";
    cout << "\"" << s1 << "\" and \"" << t1 << "\" are " 
         << (sol.isIsomorphic(s1, t1) ? "isomorphic" : "not isomorphic") << endl; // Output: isomorphic

    string s2 = "foo";
    string t2 = "bar";
    cout << "\"" << s2 << "\" and \"" << t2 << "\" are " 
         << (sol.isIsomorphic(s2, t2) ? "isomorphic" : "not isomorphic") << endl; // Output: not isomorphic
    
    return 0;
}
```

-----

## Complexity

  - **Time:** $O(N + M)$, where `N` and `M` are the lengths of strings `s` and `t`, respectively. We iterate through each string once to generate its pattern.
  - **Space:** $O(N + M)$. The `unordered_map` can store up to the number of unique characters, and the generated pattern string can have a length proportional to the original string.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o isomorphic_strings main.cpp`
  - **Run:** `./isomorphic_strings`

-----

## Notes

  - This solution works by converting each string into a "canonical pattern". For example, "egg" becomes "0 1 1 " and "add" also becomes "0 1 1 ". If the patterns are identical, the strings are isomorphic.
  - This is a clever way to check for the structural similarity required for isomorphism.
  - Another common approach is to use two hash maps: one to map characters from `s` to `t` and another to map characters from `t` to `s`. This ensures that the mapping is bijective (one-to-one).
