# Letter-Combinations-of-a-Phone-Number

A C++ program to generate all possible letter combinations that a given digit string can represent, based on a standard telephone keypad mapping.

-----

## Problem

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. A mapping of digits to letters (just like on the telephone buttons) is given. Note that `1` does not map to any letters.

-----

## Example

**Input:** `digits = "23"`

**Explanation:**

  - `2` maps to `"abc"`.
  - `3` maps to `"def"`.
    The combinations are the Cartesian product of these two sets: `{"a", "b", "c"} x {"d", "e", "f"}`.

**Output:** `["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]`

-----

## Code

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Helper to map a digit to its corresponding letters
    string getLetters(int digit) {
        switch (digit) {
            case 2: return "abc";
            case 3: return "def";
            case 4: return "ghi";
            case 5: return "jkl";
            case 6: return "mno";
            case 7: return "pqrs";
            case 8: return "tuv";
            case 9: return "wxyz";
        }
        return "";
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;

        // Start with an empty string to build upon
        res.push_back("");

        // Iterate through each digit in the input string
        for (char digit_char : digits) {
            vector<string> temp;
            string letters = getLetters(digit_char - '0');
            
            // For each existing combination...
            for (const string& prefix : res) {
                // ...append each possible letter for the current digit
                for (char c : letters) {
                    temp.push_back(prefix + c);
                }
            }
            // The temporary list becomes the new list of combinations
            res = temp;
        }

        return res;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    string digits = "23";

    vector<string> result = sol.letterCombinations(digits);

    cout << "Letter combinations for \"" << digits << "\": ";
    for (const string& s : result) {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(4^N \cdot N)$, where $N$ is the number of digits in the input string. In the worst case, each of the $N$ digits maps to 4 letters, leading to $4^N$ combinations. Each combination has a length of $N$, and string concatenation can take up to $O(N)$ time.
  - **Space:** $O(4^N \cdot N)$ to store the resulting combinations.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o letter_combinations main.cpp`
  - **Run:** `./letter_combinations`

-----

## Notes

  - This solution uses an **iterative, breadth-first search (BFS)** approach. It starts with an empty combination and, for each digit, expands the set of current combinations by appending the new possible letters.
  - The core idea is to build the solution level by level. After processing the first digit, `res` holds `["a", "b", "c"]`. After processing the second digit, `res` is updated to hold `["ad", "ae", "af", ...]`.
  - A common alternative approach to this problem is using **recursion with backtracking**, which can be more concise but conceptually similar.
