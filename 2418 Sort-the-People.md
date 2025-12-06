# 2418 Sort-the-People

A C++ program to sort a list of names based on their corresponding heights in descending order.

-----

## 📊 Difficulty Level

**Easy**

## 🔗 Problem Link

[LeetCode 2418: Sort the People](https://leetcode.com/problems/sort-the-people/)

## 🏷️ Topic Tags

  - Array
  - Hash Table
  - String
  - Sorting

-----

## Problem

You are given an array of strings `names`, and an array of distinct positive integers `heights`. Both arrays are of length `n`.

For each index `i`, `names[i]` and `heights[i]` denote the name and height of the `i`-th person.

Return `names` sorted in **descending order** by the people's heights.

-----

## Example

**Input:** `names = ["Mary", "John", "Emma"], heights = [180, 165, 170]`

**Explanation:**

1.  Mary is 180.
2.  John is 165.
3.  Emma is 170.
    Sorted by height (descending): 180 (Mary), 170 (Emma), 165 (John).

**Output:** `["Mary", "Emma", "John"]`

-----

## Code

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> res;
        
        // Combine heights and names into pairs
        for (int i = 0; i < names.size(); i++) {
            res.push_back({heights[i], names[i]});
        }
        
        // Sort in descending order based on height (the first element of the pair)
        sort(res.rbegin(), res.rend());
        
        vector<string> res1;
        // Extract the names from the sorted pairs
        for (auto &n : res) {
            res1.push_back(n.second);
        }
        
        return res1;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<string> names = {"Mary", "John", "Emma"};
    vector<int> heights = {180, 165, 170};

    vector<string> result = sol.sortPeople(names, heights);

    cout << "Sorted names: ";
    for (const string& name : result) {
        cout << "\"" << name << "\" ";
    }
    cout << endl; // Output: "Mary" "Emma" "John"

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(N \log N)$, where `N` is the number of people. Sorting the vector of pairs takes $O(N \log N)$ time. Iterating to build the pairs and extracting the result takes $O(N)$.
  - **Space:** $O(N)$, to store the vector of pairs `res` and the result vector `res1`.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o sort_people main.cpp`
  - **Run:** `./sort_people`

-----

## Notes

  - This solution uses `std::pair` to couple the height and name together. By default, `std::pair` comparisons compare the first element, then the second.
  - Since the problem asks for sorting by height, putting `height` as the first element of the pair allows `std::sort` to handle the logic automatically.
  - Using `rbegin()` and `rend()` sorts the container in reverse (descending) order efficiently.
