# Majority-Element-II

A C++ program to find all elements that appear more than `n/3` times in an array.

-----

## Problem

Given an integer array `nums` of size `n`, find all elements that appear more than `⌊ n/3 ⌋` times.

-----

## Example

**Input:** `nums = [3, 2, 3]`

**Explanation:**
The size of the array is `n = 3`. The limit is `⌊ 3/3 ⌋ = 1`.

  - The number `3` appears 2 times, which is greater than 1.
  - The number `2` appears 1 time, which is not greater than 1.
    Therefore, `3` is the only majority element.

**Output:** `[3]`

-----

## Code

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int limit = nums.size() / 3;
        unordered_map<int, int> freqMap;
        vector<int> result;

        // Count frequencies of each number
        for (int n : nums) {
            freqMap[n]++;
        }

        // Find numbers with frequency greater than the limit
        for (auto const& [num, count] : freqMap) {
            if (count > limit) {
                result.push_back(num);
            }
        }
        return result;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums = {3, 2, 3};

    vector<int> result = sol.majorityElement(nums);

    cout << "Elements appearing more than n/3 times: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: 3

    vector<int> nums2 = {1, 2, 2, 3, 3, 3, 1};
    result = sol.majorityElement(nums2); // n=7, limit=2. 3 appears 3 times.
    cout << "Elements appearing more than n/3 times: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: 3

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(n)$, where `n` is the number of elements in the array. We iterate through the array once to build the frequency map and then iterate through the map (which has at most `n` unique elements).
  - **Space:** $O(n)$ in the worst case. If all elements in the array are unique, the `unordered_map` will store `n` key-value pairs.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o majority_element main.cpp`
  - **Run:** `./majority_element`

-----

## Notes

  - This solution uses a hash map to count the frequencies of each element, which is a simple and intuitive approach.
  - A key insight for this problem is that there can be at most **two** such majority elements.
  - An optimized solution with $O(1)$ space complexity can be achieved using the **Boyer-Moore Voting Algorithm**, extended to handle two candidates. This algorithm finds the potential majority candidates in a single pass without using extra storage proportional to the input size.
