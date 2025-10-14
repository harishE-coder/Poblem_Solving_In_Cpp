# Find-Indices-After-Peaks

A C++ program to find the indices of elements that immediately follow an element exceeding a specific threshold.

-----

## Problem

You are given a 0-indexed integer array `height` representing altitudes and an integer `threshold`. Your task is to identify all indices `i` such that the height at the preceding index, `height[i-1]`, is strictly greater than the `threshold`.

-----

## Example

**Input:** `height = [10, 25, 20, 35, 30]`, `threshold = 22`

**Explanation:**

  - For `i = 1`, `height[0]` (10) is not \> 22.
  - For `i = 2`, `height[1]` (25) is \> 22. Add index `2` to the result.
  - For `i = 3`, `height[2]` (20) is not \> 22.
  - For `i = 4`, `height[3]` (35) is \> 22. Add index `4` to the result.

The final list of indices is `[2, 4]`.

**Output:** `[2, 4]`

-----

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        int k = height.size();
        vector<int> res;
        for (int i = 1; i < k; i++) {
            // Check if the PREVIOUS height is greater than the threshold
            if (height[i - 1] > threshold) {
                // If it is, add the CURRENT index to the result
                res.push_back(i);
            }
        }
        return res;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> height = {10, 25, 20, 35, 30};
    int threshold = 22;

    vector<int> result = sol.stableMountains(height, threshold);

    cout << "Indices following a height greater than " << threshold << ": ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl; // Output: 2 4

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(n)$, where `n` is the number of elements in the `height` array. The solution involves a single pass through the array.
  - **Space:** $O(n)$ in the worst case, as the result vector could potentially store `n-1` indices.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o stable_mountains main.cpp`
  - **Run:** `./stable_mountains`

-----

## Notes

  - The logic is a straightforward linear scan. The loop starts at index `1` to prevent out-of-bounds access when checking the element at `i-1`.
  - The function name `stableMountains` might be abstract; the code's concrete function is to find indices that follow a value greater than a threshold.
