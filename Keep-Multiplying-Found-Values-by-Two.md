# Keep-Multiplying-Found-Values-by-Two

A C++ program to find a final integer by repeatedly multiplying an original value by 2 if it is found in an array.

-----

## Problem

You are given an array of integers `nums` and an integer `original`. You need to perform the following steps:

1.  Search for `original` in `nums`.
2.  If `original` is found, multiply it by two (i.e., set `original = 2 * original`).
3.  Otherwise, stop the process.
4.  Repeat this process with the new number as long as you keep finding the number.

Return the final value of `original`.

-----

## Example

**Input:** `nums = [5, 3, 6, 1, 12]`, `original = 3`

**Explanation:**

1.  `3` is found in `nums`. `original` becomes `3 * 2 = 6`.
2.  `6` is found in `nums`. `original` becomes `6 * 2 = 12`.
3.  `12` is found in `nums`. `original` becomes `12 * 2 = 24`.
4.  `24` is not found in `nums`. The process stops.

**Output:** `24`

-----

## Code

```cpp
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        // Use a hash set for O(1) average time complexity lookups
        unordered_set<int> set(nums.begin(), nums.end());
        
        // While the current 'original' value exists in the set, double it
        while (set.count(original)) {
            original *= 2;
        }
        
        return original;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums = {5, 3, 6, 1, 12};
    int original = 3;

    int result = sol.findFinalValue(nums, original);

    cout << "Final value: " << result << endl; // Output: 24

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(N)$, where `N` is the length of `nums`.
      - Converting the vector to an `unordered_set` takes $O(N)$ time.
      - The `while` loop runs a number of times proportional to how many times `original` can be doubled before exceeding the maximum value in the array. Since the value grows exponentially, this number is small (logarithmic relative to the value range), making the set construction the dominant operation.
  - **Space:** $O(N)$, to store the elements of the array in the hash set.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o find_final_value main.cpp`
  - **Run:** `./find_final_value`

-----

## Notes

  - Using a `vector` to search linearly inside the loop would result in a time complexity of $O(N \cdot K)$ (where K is the number of doublings).
  - By converting the `vector` to an `unordered_set` first, we reduce the search time to $O(1)$ on average, making the whole algorithm significantly faster for large inputs.
