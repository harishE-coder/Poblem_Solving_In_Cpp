# Longest-Common-Prefix

A C++ program to find the longest common prefix among an array of strings.

-----

## Problem

Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string `""`.

-----

## Example

**Input:** `strs = ["flower", "flow", "flight"]`

**Explanation:**

  - The first character 'f' is common to all strings.
  - The second character 'l' is common to all strings.
  - The third character 'o' in "flower" and "flow" does not match 'i' in "flight".
  - Therefore, the longest common prefix is "fl".

**Output:** `"fl"`

-----

## Code

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Iterate through the characters of the first string
        for (int i = 0; i < strs[0].length(); i++) {
            char currentChar = strs[0][i];
            
            // Compare this character with the character at the same position
            // in all other strings.
            for (int j = 1; j < strs.size(); j++) {
                // If a string is shorter or a character mismatches,
                // we have found the longest common prefix.
                if (i >= strs[j].length() || strs[j][i] != currentChar) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        // If the loop completes, the entire first string is the common prefix.
        return strs[0];
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};

    string result = sol.longestCommonPrefix(strs);
    cout << "The longest common prefix is: \"" << result << "\"" << endl; // Output: "fl"

    vector<string> strs2 = {"dog", "racecar", "car"};
    result = sol.longestCommonPrefix(strs2);
    cout << "The longest common prefix is: \"" << result << "\"" << endl; // Output: ""

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(S)$, where $S$ is the sum of all characters in all strings. In the worst case, all `n` strings are the same and have length `m`, so the complexity is $O(n \cdot m)$.
  - **Space:** $O(1)$, as the algorithm uses constant extra space.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o lcp main.cpp`
  - **Run:** `./lcp`

-----

## Notes

  - This solution uses a method called **Vertical Scanning**. It iterates through the characters from top to bottom (i.e., it checks the first character of all strings, then the second character of all strings, and so on).
  - This approach is efficient because it can stop as soon as a mismatch is found, without needing to process the rest of the strings.
  - An alternative approach is **Horizontal Scanning**, where you compare the first string with the second to find their common prefix, then compare that result with the third string, and so on.
  - For a very large number of strings, more advanced solutions using a **Trie** or **Binary Search** could be more performant.
