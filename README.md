# Sum-of-Elements-Divisible-by-K

C++ program to find sum of elements whose frequency is divisible by K.

---

### 💻 Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate sum of elements whose frequency is divisible by k
    int sumDivisibleByK(const vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,int> freq;

        // Count frequency of each element
        for (int n : nums) 
            freq[n]++;

        // Add elements to sum if their frequency is divisible by k
        for (auto &p : freq) {
            if (p.second % k == 0)
                sum += p.first * p.second;
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


