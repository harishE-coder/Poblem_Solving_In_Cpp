# Top-K-Frequent-Elements

A C++ program to find the `k` most frequent elements in an array.

-----

## Problem

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements. You may return the answer in any order.

-----

## Example

**Input:** `nums = [1, 1, 1, 2, 2, 3]`, `k = 2`

**Explanation:**

  - The frequency of `1` is 3.
  - The frequency of `2` is 2.
  - The frequency of `3` is 1.

The two most frequent elements are `1` and `2`.

**Output:** `[1, 2]`

-----

## Code

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count the frequency of each number
        unordered_map<int, int> freq;
        for (int n : nums) {
            freq[n]++;
        }

        // Step 2: Store frequencies and numbers as pairs
        vector<pair<int, int>> res;
        for (auto& p : freq) {
            res.push_back({p.second, p.first}); // {frequency, number}
        }

        // Step 3: Sort the pairs in descending order based on frequency
        sort(res.rbegin(), res.rend());

        // Step 4: Extract the top k elements
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(res[i].second);
        }
        return ans;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = sol.topKFrequent(nums, k);

    cout << "The top " << k << " frequent elements are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: 1 2

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(n \log n)$ in the worst case.
      - Counting frequencies with a hash map takes $O(n)$.
      - Populating the pairs vector takes $O(m)$, where `m` is the number of unique elements.
      - Sorting the `m` unique elements takes $O(m \log m)$. In the worst case, all `n` elements are unique (`m = n`), leading to a complexity of $O(n \log n)$.
  - **Space:** $O(n)$ in the worst case, to store the frequency map and the vector of pairs if all elements are unique.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o top_k_frequent main.cpp`
  - **Run:** `./top_k_frequent`

-----

## Notes

  - This solution uses a straightforward approach: count frequencies, store them in pairs, and sort by frequency to find the top `k` elements.
  - A more optimized solution can be achieved using a **min-heap (priority queue)** of size `k`. This would improve the time complexity to $O(n \log k)$, as you iterate through the `n` elements and perform heap operations that cost $O(\log k)$.
  - An even faster approach is to use a **Quickselect** algorithm (or `std::nth_element`), which can find the k-th largest element in $O(n)$ average time complexity.
