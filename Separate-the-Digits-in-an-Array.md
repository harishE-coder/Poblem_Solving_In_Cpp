# Separate-the-Digits-in-an-Array

A C++ program to separate the digits of each number in an array into a new array.

-----

## Problem

Given an array of positive integers `nums`, create a new array `answer` that consists of the digits of each integer in `nums` separated and in the same order they appear.

-----

## Example

**Input:** `nums = [13, 25, 83, 77]`

**Explanation:**

  - The digits of `13` are `1` and `3`.
  - The digits of `25` are `2` and `5`.
  - The digits of `83` are `8` and `3`.
  - The digits of `77` are `7` and `7`.
    Combining them in order gives the final array.

**Output:** `[1, 3, 2, 5, 8, 3, 7, 7]`

-----

## Code

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        for (int num : nums) {
            // Helper function to extract and append digits
            appendDigits(answer, num);
        }
        return answer;
    }

private:
    void appendDigits(vector<int>& v, int n) {
        // Convert the number to a string to easily access its digits
        string s = to_string(n);
        for (char c : s) {
            // Convert character back to integer and add to the vector
            v.push_back(c - '0');
        }
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums = {13, 25, 83, 77};

    vector<int> result = sol.separateDigits(nums);

    cout << "The separated digits are: ";
    for (int digit : result) {
        cout << digit << " ";
    }
    cout << endl; // Output: 1 3 2 5 8 3 7 7

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(D)$, where $D$ is the total number of digits in all the numbers in the input array. We process each digit exactly once.
  - **Space:** $O(D)$, to store the resulting array of digits.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o separate_digits main.cpp`
  - **Run:** `./separate_digits`

-----

## Notes

  - This solution converts each number to a string, which provides a convenient way to iterate over its digits.
  - The expression `c - '0'` is a standard C++ idiom for converting a character digit (e.g., '5') to its integer equivalent (e.g., 5).
  - An alternative approach without string conversion would involve using a `while` loop with modulo (`% 10`) and division (`/ 10`) operations to extract digits from right to left. However, this would require reversing the digits for each number to maintain the correct order.
