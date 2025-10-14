# Valid-Parentheses

A C++ program to determine if a string of brackets is valid.

-----

## Problem

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1.  Open brackets must be closed by the same type of brackets.
2.  Open brackets must be closed in the correct order.
3.  Every close bracket has a corresponding open bracket of the same type.

-----

## Example

**Input:** `s = "()[]{}"`

**Explanation:**

  - `(` is opened, then closed by `)`.
  - `[` is opened, then closed by `]`.
  - `{` is opened, then closed by `}`.
    All brackets are matched correctly.

**Output:** `true`

**Input:** `s = "(]"`

**Output:** `false`

-----

## Code

```cpp
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            // If it's an opening bracket, push it onto the stack
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            // If it's a closing bracket
            else {
                // If the stack is empty, there's no matching open bracket
                if (st.empty()) return false;
                
                char top = st.top();
                // Check if the closing bracket matches the top of the stack
                if ((top == '(' && c == ')') ||
                    (top == '[' && c == ']') ||
                    (top == '{' && c == '}')) {
                    st.pop(); // Match found, pop the open bracket
                } else {
                    return false; // Mismatch
                }
            }
        }
        // If the stack is empty at the end, all brackets were matched
        return st.empty();
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    string s1 = "()[]{}";
    cout << s1 << " is " << (sol.isValid(s1) ? "valid" : "invalid") << endl; // Output: valid

    string s2 = "(]";
    cout << s2 << " is " << (sol.isValid(s2) ? "valid" : "invalid") << endl; // Output: invalid

    string s3 = "{[]}";
    cout << s3 << " is " << (sol.isValid(s3) ? "valid" : "invalid") << endl; // Output: valid
    
    return 0;
}
```

-----

## Complexity

  - **Time:** $O(n)$, where `n` is the length of the string. We perform a single pass through the string.
  - **Space:** $O(n)$, in the worst-case scenario where the string consists of only opening brackets, the stack will store all `n` characters.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o valid_parentheses main.cpp`
  - **Run:** `./valid_parentheses`

-----

## Notes

  - This problem is a classic use case for the **stack** data structure.
  - The **Last-In, First-Out (LIFO)** nature of a stack perfectly models the nested structure of brackets. The last opening bracket you see must be the first one to be closed.
  - When an opening bracket is encountered, it's pushed onto the stack.
  - When a closing bracket is found, the top of the stack is checked. If it's the corresponding opening bracket, the opening bracket is popped from the stack. Otherwise, the string is invalid.
  - After iterating through the entire string, the stack must be empty for the string to be valid. A non-empty stack indicates unclosed opening brackets.
