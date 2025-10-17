# Two-Sum

A C++ program to find the indices of two numbers in an array that add up to a specific target.

-----

## Problem

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to `target`.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice. You can return the answer in any order.

-----

## Example

**Input:** `nums = [2, 7, 11, 15]`, `target = 9`

**Explanation:**
Because `nums[0] + nums[1] == 2 + 7 == 9`, we return `[0, 1]`.

**Output:** `[0, 1]`

-----

## Code

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // Key: number, Value: index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if the complement exists in the map
            if (numMap.find(complement) != numMap.end()) {
                // If it exists, we found our pair
                return {numMap[complement], i};
            }
            
            // If complement is not found, add the current number and its index to the map
            numMap[nums[i]] = i;
        }

        // Return an empty vector if no solution is found (though problem assumes one exists)
        return {};
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices found: [" << result[0] << ", " << result[1] << "]" << endl; // Output: [0, 1]
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(n)$, where `n` is the number of elements in the array. We traverse the list containing `n` elements only once. Each lookup in the hash map (`numMap`) is, on average, $O(1)$.
  - **Space:** $O(n)$, in the worst case, we might store all `n` elements in the hash map.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o two_sum main.cpp`
  - **Run:** `./two_sum`

-----

## Notes

  - The provided solution uses an **`unordered_map`** (a hash map) to achieve a single-pass solution. This is the most efficient approach for this problem.
  - The map stores the numbers we've already seen and their corresponding indices.
  - For each element `nums[i]`, we calculate its `complement` (the other number we need to reach the `target`). We then check if this `complement` is already in our map. If it is, we've found our solution.
  - The user's original code attempted a two-pointer approach. While that is a valid technique for finding pairs in a **sorted** array, it doesn't work here because sorting the array loses the **original indices** that the problem asks for.
