Got it. Here is the response with the requested GitHub-friendly Markdown formatting.

# Successful-Pairs-of-Spells-and-Potions

A C++ program to find the number of successful pairs of spells and potions.

## Problem

You are given two positive integer arrays `spells` and `potions`, of length `n` and `m` respectively, where `spells[i]` represents the strength of the `i`-th spell and `potions[j]` represents the strength of the `j`-th potion. You are also given an integer `success`. A spell and potion pair is considered successful if the product of their strengths is **at least** `success`.

Return an integer array `pairs` of length `n` where `pairs[i]` is the number of potions that will form a successful pair with the `i`-th spell.

## Example

**Input:** `spells = [5, 1, 3]`, `potions = [1, 2, 3, 4, 5]`, `success = 7`

**Explanation:**

  - For the 1st spell (`5`): We need potions with strength at least `ceil(7/5) = 2`. The potions are `[2, 3, 4, 5]`, so there are 4 successful pairs.
  - For the 2nd spell (`1`): We need potions with strength at least `ceil(7/1) = 7`. There are no such potions, so there are 0 successful pairs.
  - For the 3rd spell (`3`): We need potions with strength at least `ceil(7/3) = 3`. The potions are `[3, 4, 5]`, so there are 3 successful pairs.

**Output:** `[4, 0, 3]`

## Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long su) {
        vector<int> res;
        sort(p.begin(), p.end());
        for (int S : s) {
            long long need = ceil((double)su / S);
            // Find the first potion that is strong enough
            auto it = lower_bound(p.begin(), p.end(), need);
            int pos = it - p.begin();
            // All potions from this position to the end are successful
            int cnt = p.size() - pos;
            res.push_back(cnt);
        }
        return res;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 7;

    vector<int> result = sol.successfulPairs(spells, potions, success);

    cout << "Successful pairs count for each spell: ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl; // Output: 4 0 3

    return 0;
}
```

## Complexity

  - **Time:** `O(m log m + n log m)`, where `n` is the number of spells and `m` is the number of potions. Sorting the `potions` array takes `O(m log m)`. For each of the `n` spells, we perform a binary search on the `potions` array, which takes `O(log m)`.
  - **Space:** `O(n)` to store the result array. Some space may also be used by the sorting algorithm, typically `O(log m)`.

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o successful_pairs main.cpp`
  - **Run:** `./successful_pairs`

## Notes

  - Sorting the `potions` array is key to using an efficient binary search (`lower_bound`) for each spell.
  - The required potion strength `need` is calculated using `ceil((double)su / S)` to handle cases where the division is not an integer. For example, if `success` is 7 and `spell` is 3, we need a potion of at least `2.33...`, which means a potion of strength 3 or more.
  - Using `long long` for the `success` value and the `need` calculation helps prevent potential integer overflow issues.
