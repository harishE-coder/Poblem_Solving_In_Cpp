//Sum-of-Elements-Divisible-by-K
//C++ program to find sum of elements whose frequency is divisible by K


class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,int> freq;
        
        for (int n : nums)
            freq[n]++;
        
        for (auto &n : freq) {
            if (n.second % k == 0)
                sum += n.first * n.second;
        }
        
        return sum;
    }
};

