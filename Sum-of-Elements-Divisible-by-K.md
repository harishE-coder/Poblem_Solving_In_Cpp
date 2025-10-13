# Sum-of-Elements-Divisible-by-K

C++ program to compute the sum of elements whose frequency in an array is divisible by K.

## Problem
Given an array of integers and an integer K, find the sum of all elements whose frequency in the array is divisible by K. For each value v whose count c satisfies c % K == 0, add v * c to the result.

Example:
- Input: nums = [2, 2, 3, 3, 3, 4], K = 2
- Frequencies: 2 -> 2, 3 -> 3, 4 -> 1
- Elements with frequency divisible by 2: 2 (count 2) → contribute 2 * 2 = 4
- Output: 4

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate sum of elements whose frequency is divisible by k
    long long sumDivisibleByK(const vector<int>& nums, int k) {
        if (k <= 0) {
            // undefined for k <= 0; could throw or return 0 depending on desired behavior
            throw invalid_argument("k must be a positive integer");
        }

        long long sum = 0;
        unordered_map<int,int> freq;

        // Count frequency of each element
        for (int n : nums) 
            freq[n]++;

        // Add elements to sum if their frequency is divisible by k
        for (auto &p : freq) {
            if (p.second % k == 0)
                sum += static_cast<long long>(p.first) * p.second;
        }

        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 3, 3, 3, 4};
    int k = 2;
    cout << "Sum: " << sol.sumDivisibleByK(nums, k) << endl; // Output: 4
    return 0;
}
```

## Complexity
- Time: O(n), where n is the number of elements (counting frequencies and single pass over map).
- Space: O(m), where m is the number of distinct elements (for the frequency map).

## Build & Run
- Compile: g++ -std=c++17 -O2 -o sum_by_k main.cpp
- Run: ./sum_by_k

## Notes
- Ensure K > 0. The sample implementation throws an exception for k <= 0 — you may adapt that to return 0 or handle differently depending on your use case.
- Use 64-bit accumulation (long long) if input values or counts can be large to avoid overflow.

License: feel free to add a LICENSE file if you want an explicit license for the repo.
