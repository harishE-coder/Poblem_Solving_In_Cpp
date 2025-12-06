# 2716 Minimize-String-Length

A C++ program to find the minimum possible length of a string after removing duplicate characters.

-----

## 📊 Difficulty Level

**Easy**

## 🔗 Problem Link

[LeetCode 2716: Minimize String Length](https://leetcode.com/problems/minimize-string-length/)

## 🏷️ Topic Tags

  - Hash Table
  - String

-----

## Problem

Given a **0-indexed** string `s`, repeatedly perform the following operation any number of times:

1.  Choose an index `i` in the string, and let `c` be the character at position `i`.
2.  Delete the **closest occurrence** of `c` to the left of `i` (if any) and the **closest occurrence** of `c` to the right of `i` (if any).

Your task is to minimize the length of `s` by performing the above operation any number of times. Return an integer denoting the length of the **minimized** string.

*Effectively, this problem asks for the number of **distinct** characters in the string.*

-----

## Example

**Input:** `s = "aaabc"`

**Explanation:**

  - Operation on 'a': We can remove the extra 'a's.
  - The string reduces to containing one 'a', one 'b', and one 'c'.
  - The minimized string is "abc".
  - The length is 3.

**Output:** `3`

**Input:** `s = "cbbd"`

**Explanation:**

  - The distinct characters are 'c', 'b', and 'd'.
  - The length is 3.

**Output:** `3`

-----

## Code

```cpp
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minimizedStringLength(string s) {
        // C++17 allows template argument deduction: unordered_set f(s.begin(), s.end());
        // For broader compatibility, we specify <char>.
        unordered_set<char> f(s.begin(), s.end());
        return f.size();
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    string s1 = "aaabc";
    cout << "Minimized length of \"" << s1 << "\": " << sol.minimizedStringLength(s1) << endl; // Output: 3

    string s2 = "cbbd";
    cout << "Minimized length of \"" << s2 << "\": " << sol.minimizedStringLength(s2) << endl; // Output: 3

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(N)$, where `N` is the length of the string. We iterate through the string once to insert characters into the hash set.
  - **Space:** $O(1)$ (or $O(\Sigma)$). Since the input consists of lowercase English letters, the hash set will store at most 26 unique characters, which is constant space.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o minimize_string main.cpp`
  - **Run:** `./minimize_string`

-----

## Notes

  - Although the problem description describes a complex deletion operation, the logical outcome is that you can keep exactly one instance of every character present in the string.
  - Therefore, the problem simplifies to: **"Count the number of unique characters in the string."**
  - Using an `unordered_set` is the most direct way to filter for unique elements.
