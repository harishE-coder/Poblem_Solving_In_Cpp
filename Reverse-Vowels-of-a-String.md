# Reverse-Vowels-of-a-String

A C++ program to reverse only the vowels of a string.

-----

## Problem

Given a string `s`, reverse only all the vowels in the string and return it. The vowels are 'a', 'e', 'i', 'o', 'u', and they can appear in both lower and upper cases, more than once. Consonants should remain in their original positions.

-----

## Example

**Input:** `s = "hello"`

**Explanation:**
The vowels in "hello" are 'e' and 'o'. The two-pointer approach finds 'e' from the left and 'o' from the right. They are swapped, resulting in "holle".

**Output:** `"holle"`

-----

## Code

```cpp
#include <iostream>
#include <string>
#include <algorithm> // For std::swap
#include <cctype>    // For tolower

using namespace std;

class Solution {
public:
    // Helper function to check if a character is a vowel
    bool isVowel(char c) {
        c = tolower(c); // Makes checking case-insensitive
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            // Find the next vowel from the left
            while (left < right && !isVowel(s[left])) {
                left++;
            }

            // Find the next vowel from the right
            while (left < right && !isVowel(s[right])) {
                right--;
            }

            // If left is still less than right, we have found two vowels to swap
            if (left < right) {
                std::swap(s[left], s[right]);
                left++;  // Move pointers inward after a swap
                right--;
            }
        }
        return s;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    string s1 = "hello";
    cout << "Original: " << s1 << ", Reversed Vowels: " << sol.reverseVowels(s1) << endl; // Output: holle

    string s2 = "leetcode";
    cout << "Original: " << s2 << ", Reversed Vowels: " << sol.reverseVowels(s2) << endl; // Output: leotcede

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(n)$, where `n` is the length of the string. In the worst case, each pointer traverses the entire string once.
  - **Space:** $O(1)$, as the string is modified in-place. The space used by the pointers is constant.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o reverse_vowels main.cpp`
  - **Run:** `./reverse_vowels`

-----

## Notes

  - This solution uses the **two-pointer** technique, which is very efficient for in-place modifications from opposite ends of a sequence.
  - One pointer (`left`) starts from the beginning of the string, and the other (`right`) starts from the end.
  - The pointers move towards each other, stopping only when they find vowels. Once both have found a vowel, the characters are swapped.
  - The helper function `isVowel` simplifies the logic and handles both uppercase and lowercase vowels by converting the character to lowercase before checking.
