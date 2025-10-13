# Longest-Palindromic-Substring

A C++ program to find the longest palindromic substring in a given string.

-----

## Problem

Given a string `s`, find the longest substring of `s` that is also a palindrome. A palindrome is a string that reads the same backward as forward.

-----

## Example

**Input:** `s = "babad"`

**Explanation:**
The substrings are "b", "a", "b", "a", "d", "ba", "ab", "ba", "ad", "bab", "aba", "bad", "baba", "abad", "babad".
The palindromic substrings are "b", "a", "b", "a", "d", "bab", "aba".
The longest palindromic substrings are "bab" and "aba". Either is a valid answer.

**Output:** `"bab"` (or `"aba"`)

-----

## Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Helper function to expand around a center and find the longest palindrome
    string expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the palindrome found
        return s.substr(left + 1, right - (left + 1));
    }

    string longestPalindrome(string s) {
        if (s.length() < 1) return "";
        
        string longest = "";

        for (int i = 0; i < s.length(); i++) {
            // Case 1: Odd length palindrome (center is a single character)
            string oddPalindrome = expandAroundCenter(s, i, i);
            if (oddPalindrome.length() > longest.length()) {
                longest = oddPalindrome;
            }

            // Case 2: Even length palindrome (center is between two characters)
            string evenPalindrome = expandAroundCenter(s, i, i + 1);
            if (evenPalindrome.length() > longest.length()) {
                longest = evenPalindrome;
            }
        }
        return longest;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    string s = "babad";

    string result = sol.longestPalindrome(s);

    cout << "The longest palindromic substring is: \"" << result << "\"" << endl; // Output: "bab"

    string s2 = "cbbd";
    result = sol.longestPalindrome(s2);
    cout << "The longest palindromic substring is: \"" << result << "\"" << endl; // Output: "bb"

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(n^2)$, where `n` is the length of the string. We iterate through each character as a potential center, and the `expandAroundCenter` function can take up to $O(n)$ time in the worst case for each center.
  - **Space:** $O(1)$, as we are not using any significant extra space that scales with the input size. The space for the result string is not counted.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o longest_palindrome main.cpp`
  - **Run:** `./longest_palindrome`

-----

## Notes

  - This solution uses the **"Expand Around Center"** approach. The main idea is that every palindrome has a center.
  - A center can be a single character (for odd-length palindromes like "aba") or the space between two characters (for even-length palindromes like "abba").
  - The algorithm iterates through all `2n - 1` possible centers and expands outwards to find the longest palindrome for that center.
  - A more advanced but complex solution is **Manacher's Algorithm**, which can solve this problem in $O(n)$ time.
