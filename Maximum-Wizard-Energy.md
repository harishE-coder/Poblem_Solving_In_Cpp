# Maximum-Wizard-Energy

A C++ program to calculate the maximum energy a wizard can gain by jumping through an array.

-----

## Problem

You are given a 0-indexed integer array `energy` of length `n` and an integer `k`. A wizard can start their journey at any index `i` where `0 <= i < n`. From index `i`, they gain `energy[i]` energy and then jump to index `i + k`. This process is repeated until they jump past the end of the array.

Your task is to find the maximum possible total energy the wizard can gain.

-----

## Example

**Input:** `energy = [5, 2, -10, -5, 1]`, `k = 3`

**Explanation:**

  - If the wizard starts at index `0`: Total energy = `energy[0] + energy[3] = 5 + (-5) = 0`.
  - If the wizard starts at index `1`: Total energy = `energy[1] + energy[4] = 2 + 1 = 3`.
  - If the wizard starts at index `2`: Total energy = `energy[2] = -10`.
  - If the wizard starts at index `3`: Total energy = `energy[3] = -5`.
  - If the wizard starts at index `4`: Total energy = `energy[4] = 1`.

The maximum energy gain is 3.

**Output:** `3`

-----

## Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& arr, int k) {
        int n = arr.size();
        // Iterate backward from the last possible starting point of a multi-step path
        for (int i = n - 1 - k; i >= 0; i--) {
            // Add the energy from the next jump (i + k) to the current position i
            arr[i] += arr[i + k];
        }
        // The maximum value in the modified array is the answer
        return *max_element(arr.begin(), arr.end());
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    vector<int> energy = {5, 2, -10, -5, 1};
    int k = 3;

    int result = sol.maximumEnergy(energy, k);

    cout << "The maximum energy the wizard can gain is: " << result << endl; // Output: 3

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(n)$, where `n` is the number of elements in the array. The algorithm consists of a single loop that iterates through the array once, followed by `max_element` which also takes $O(n)$.
  - **Space:** $O(1)$, as the solution modifies the input array in-place and does not use any extra space that scales with the input size.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o max_energy main.cpp`
  - **Run:** `./max_energy`

-----

## Notes

  - This solution uses a clever **dynamic programming** approach.
  - By iterating backward, it calculates the cumulative energy for each possible path. When the loop is at index `i`, the value `arr[i + k]` has already been updated to contain the total energy from the path starting at `i + k`.
  - Therefore, `arr[i] += arr[i + k]` updates `arr[i]` to store the total energy for the entire path starting from `i`.
  - After the loop, the array `arr` is transformed such that each `arr[i]` holds the total energy for a path starting at that index. The maximum element in this modified array is the final answer.
