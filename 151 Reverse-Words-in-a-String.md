# 151 Reverse-Words-in-a-String

A C++ program to reverse the order of words in a given string.

-----

## 📊 Difficulty Level

**Medium**

## 🔗 Problem Link

[LeetCode 151: Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/)

## 🏷️ Topic Tags

  - Two Pointers
  - String

-----

## Problem

Given an input string `s`, reverse the order of the **words**.

A **word** is defined as a sequence of non-space characters. The **words** in `s` will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

**Note:** `s` may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

-----

## Example

**Input:** `s = "the sky is blue"`

**Explanation:**
The words are "the", "sky", "is", "blue".
Reversed: "blue", "is", "sky", "the".

**Output:** `"blue is sky the"`

**Input:** `s = "  hello world  "`

**Explanation:**
The input string has leading and trailing spaces. These should be ignored.
The words are "hello", "world".
Reversed: "world", "hello".

**Output:** `"world hello"`

-----

## Code

```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string word;
        string res = "";
        stringstream ss(s);
        
        // Extract words one by one. stringstream automatically skips whitespace.
        while (ss >> word) {
            // Prepend the current word to the result
            res = word + " " + res;
        }
        
        // Remove the trailing space added in the loop
        if (!res.empty()) {
            res.pop_back();
        }
        
        return res;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    string s1 = "the sky is blue";
    cout << "Original: \"" << s1 << "\"" << endl;
    cout << "Reversed: \"" << sol.reverseWords(s1) << "\"" << endl; // Output: "blue is sky the"

    string s2 = "  hello world  ";
    cout << "Original: \"" << s2 << "\"" << endl;
    cout << "Reversed: \"" << sol.reverseWords(s2) << "\"" << endl; // Output: "world hello"

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(N)$, where `N` is the length of the string. We traverse the string once using `stringstream`. Note: String concatenation inside the loop (`res = word + ...`) can technically degrade performance to $O(N^2)$ in C++ depending on string length, but it is acceptable for typical interview constraints. A `vector` or `stack` approach avoids this.
  - **Space:** $O(N)$, to store the resulting string and the individual words extracted by the stream.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o reverse_words main.cpp`
  - **Run:** `./reverse_words`

-----

## Notes

  - This solution leverages the `stringstream` class, which is very powerful for parsing strings. It automatically handles:
    1.  Skipping leading spaces.
    2.  Treating multiple spaces between words as a single delimiter.
    3.  Skipping trailing spaces.
  - The logic `res = word + " " + res` builds the result in reverse order by placing the newest word at the *front* of the string.
  - **Edge Case:** If the input string is empty or contains only spaces, `res` will remain empty. The check `if (!res.empty())` prevents undefined behavior when calling `pop_back()`.
