# Take-Gifts-From-the-Richest-Pile

A C++ program to calculate the remaining number of gifts after repeatedly taking from the richest pile.

-----

## Problem

You are given an integer array `gifts` representing the number of gifts in various piles, and an integer `k`. In each of the `k` seconds, you will perform the following action:

1.  Choose the pile with the maximum number of gifts. If there are multiple such piles, you can choose any of them.
2.  Take gifts from the chosen pile, leaving behind the floor of the square root of the original number of gifts.

Your task is to return the total number of gifts remaining in all piles after `k` seconds.

-----

## Example

**Input:** `gifts = [25, 64, 9, 4, 100]`, `k = 4`

**Explanation:**

  - **Second 1:** The richest pile is `100`. Take gifts, leaving `sqrt(100) = 10`. Piles: `[25, 64, 9, 4, 10]`.
  - **Second 2:** The richest pile is `64`. Take gifts, leaving `sqrt(64) = 8`. Piles: `[25, 9, 4, 10, 8]`.
  - **Second 3:** The richest pile is `25`. Take gifts, leaving `sqrt(25) = 5`. Piles: `[9, 4, 10, 8, 5]`.
  - **Second 4:** The richest pile is `10`. Take gifts, leaving `sqrt(10) = 3`. Piles: `[9, 4, 8, 5, 3]`.

The total number of remaining gifts is `9 + 4 + 8 + 5 + 3 = 29`.

**Output:** `29`

-----

## Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& arr, int k) {
        // A max-heap to efficiently find the largest pile
        priority_queue<int> res(arr.begin(), arr.end());

        for (int i = 0; i < k; i++) {
            // Get the richest pile
            long long root = res.top();
            res.pop();
            
            // Replace it with the square root
            root = sqrt(root);
            res.push(root);
        }

        // Sum up the remaining gifts
        long long sum = 0;
        while (!res.empty()) {
            sum += res.top();
            res.pop();
        }
        return sum;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> gifts = {25, 64, 9, 4, 100};
    int k = 4;

    long long result = sol.pickGifts(gifts, k);

    cout << "Total remaining gifts after " << k << " seconds: " << result << endl; // Output: 29

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(k \log n + n \log n)$, where `n` is the number of piles.
      - Building the initial priority queue takes $O(n)$.
      - The main loop runs `k` times, with each `pop` and `push` operation taking $O(\log n)$ time. This part is $O(k \log n)$.
      - Summing the results at the end requires removing all `n` elements, taking $O(n \log n)$.
  - **Space:** $O(n)$ to store the elements in the priority queue.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o pick_gifts main.cpp`
  - **Run:** `./pick_gifts`

-----

## Notes

  - A **`priority_queue`** (which is a max-heap by default in C++) is the ideal data structure for this problem. It allows for efficient retrieval ($O(1)$ for `top`) and removal ($O(\log n)$ for `pop`) of the maximum element.
  - The use of `long long` for the sum is a good practice to prevent potential integer overflow if the number of gifts becomes very large.
  - The final summation loop could be slightly optimized by iterating through the underlying container of the priority queue if direct access is possible, but popping each element is a standard and safe way to process all items.
