# 11 Container-With-Most-Water

A C++ program to find two lines that together with the x-axis form a container, such that the container contains the most water.

-----

## 📊 Difficulty Level

**Medium**

## 🔗 Problem Link

[LeetCode 11: Container With Most Water](https://leetcode.com/problems/container-with-most-water/)

## 🏷️ Topic Tags

  - Array
  - Two Pointers
  - Greedy

-----

## Problem

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `i`-th line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

**Note:** You may not slant the container.

-----

## Example

**Input:** `height = [1,8,6,2,5,4,8,3,7]`

**Explanation:**
The vertical lines are represented by the array `[1,8,6,2,5,4,8,3,7]`.
The max area is obtained by choosing the 2nd line (height 8) and the last line (height 7).

  - **Height:** `min(8, 7) = 7`
  - **Width:** `8 (index) - 1 (index) = 7`
  - **Area:** `7 * 7 = 49`

**Output:** `49`

-----

## Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // For max, min

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        int max_area = 0;

        // Two-pointer approach
        while (left < right) {
            // Calculate the current area
            // Height is limited by the shorter line
            int h = min(arr[left], arr[right]);
            int w = right - left;
            
            // Update maximum area if the current one is larger
            max_area = max(max_area, h * w);

            // Move the pointer of the shorter line inward
            // Logic: Moving the taller line will only decrease width without 
            // potentially increasing height (since height is limited by the shorter one).
            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int result = sol.maxArea(height);

    cout << "The maximum amount of water is: " << result << endl; // Output: 49

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(n)$, where `n` is the size of the array. The two pointers traverse the array exactly once (one from the left, one from the right).
  - **Space:** $O(1)$. We only use a few variables for the pointers and the maximum area calculation.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o container_water main.cpp`
  - **Run:** `./container_water`

-----

## Notes

  - This is a classic **Two Pointers** problem.
  - The core logic is the greedy decision to move the pointer pointing to the **shorter** line.
  - **Why?** The area is determined by the shorter line. If we move the pointer of the taller line, the width decreases, and the height can *at best* stay the same (limited by the existing short line). Thus, the area can only decrease.
  - By moving the shorter line, we hope to find a taller line that might compensate for the decrease in width.
