**567 Permutation in String**

A C++ program to check if one string's permutation is a substring of another string.

## 📊 Difficulty Level

Medium

## 🔗 Problem Link

[LeetCode 567: Permutation in String](https://leetcode.com/problems/permutation-in-string/)

## 🏷️ Topic Tags

String
Sliding Window
Two Pointers
Hash Table

## Problem

Given two strings `s1` and `s2`, return `true` if `s2` contains a permutation of `s1`, or `false` otherwise.

In other words, return `true` if one of `s1`'s permutations is the substring of `s2`.

## Example

**Input:** `s1 = "ab", s2 = "eidbaooo"`
**Explanation:**

1.  Length of `s1` is 2. We look for a window of size 2 in `s2` that has one 'a' and one 'b'.
2.  Window "ei": `{'e':1, 'i':1}`. Match `s1`? No.
3.  Window "id": `{'i':1, 'd':1}`. Match `s1`? No.
4.  Window "db": `{'d':1, 'b':1}`. Match `s1`? No.
5.  Window "ba": `{'b':1, 'a':1}`. Match `s1`? Yes.
    **Output:** `true`

**Input:** `s1 = "ab", s2 = "eidboaoo"`
**Output:** `false`

## Code

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // If s1 is longer than s2, s2 cannot contain a permutation of s1
        if (s1.size() > s2.size()) return false;
        
        // Frequency vectors for characters 'a'-'z'
        vector<int> f1(26, 0), f2(26, 0);
        
        // Count frequency of chars in s1
        for (char c : s1) {
            f1[c - 'a']++;
        }
        
        int k = s1.size();
        
        // Initialize the first window of size k in s2
        for (int i = 0; i < k; i++) {
            f2[s2[i] - 'a']++;
        }
        
        // Check if the first window matches
        if (f1 == f2) return true;
        
        // Slide the window across s2
        for (int i = k; i < s2.size(); i++) {
            // Add the new character entering the window
            f2[s2[i] - 'a']++;
            
            // Remove the old character leaving the window
            f2[s2[i - k] - 'a']--;
            
            // Check if the current window matches
            if (f1 == f2) return true;
        }
        
        return false;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    string s1 = "ab";
    string s2 = "eidbaooo";

    bool result = sol.checkInclusion(s1, s2);

    cout << "Contains permutation: " << (result ? "true" : "false") << endl; // Output: true

    return 0;
}
```

## Complexity

  * **Time:** $O(N)$, where $N$ is the length of `s2`. We iterate through `s2` once. The vector comparison `f1 == f2` takes constant time $O(26) \approx O(1)$.
  * **Space:** $O(1)$. We use two fixed-size vectors of length 26, which does not depend on the input size.

## Build & Run

  * **Compile:** `g++ -std=c++17 -O2 -o permutation_string main.cpp`
  * **Run:** `./permutation_string`

## Notes

  * **Fixed Window Size:** The window size is always equal to `s1.size()`.
  * **Vector Comparison:** In C++, `std::vector` supports direct comparison using `==`, which checks if all elements are identical. Since the vectors are small (size 26), this is very efficient.
  * **Optimization:** This solution is already optimal ($O(N)$ time), but you could optimize the comparison further by maintaining a count of "matches" instead of comparing the full vector every time, though the difference is negligible for an alphabet of size 26.
