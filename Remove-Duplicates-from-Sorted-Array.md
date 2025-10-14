# Remove-Duplicates-from-Sorted-Array

A C++ program to remove duplicates from a sorted array in-place.

-----

## Problem

Given a sorted integer array `nums`, remove the duplicates **in-place** such that each unique element appears only once. The relative order of the elements should be kept the same.

Return `k`, the number of unique elements in `nums`. The first `k` elements of `nums` should hold the final result. It does not matter what you leave beyond the returned `k`.

-----

## Example

**Input:** `nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]`

**Explanation:**
The function should return `k = 5`, with the first five elements of `nums` being modified to `0, 1, 2, 3, 4`. The values beyond the 5th element are not important.

**Output:** `5`, with `nums` becoming `[0, 1, 2, 3, 4, _, _, _, _, _]`

-----

## Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0; // Slow pointer for the position of the last unique element
        
        // Fast pointer 'j' iterates through the array to find the next unique element
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j]; // Move the new unique element to its correct position
            }
        }
        
        // The number of unique elements is the index of the last unique element + 1
        return i + 1;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    int k = sol.removeDuplicates(nums);

    cout << "Number of unique elements: " << k << endl; // Output: 5
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " "; // Output: 0 1 2 3 4
    }
    cout << endl;

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(n)$, where `n` is the number of elements in the array. Both the slow and fast pointers traverse the array at most once.
  - **Space:** $O(1)$, as the algorithm modifies the array in-place without using any extra space that scales with the input size.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o remove_duplicates main.cpp`
  - **Run:** `./remove_duplicates`

-----

## Notes

  - This solution uses the **two-pointer** technique, which is highly efficient for in-place array manipulations.
  - The **slow pointer (`i`)** keeps track of the end of the unique elements subarray.
  - The **fast pointer (`j`)** scans the array.
  - When `nums[j]` is different from `nums[i]`, it means a new unique element has been found. This unique element is then placed at the position right after the last unique element (i.e., at `nums[i+1]`), and the slow pointer `i` is incremented.
  - The final number of unique elements is `i + 1`.
