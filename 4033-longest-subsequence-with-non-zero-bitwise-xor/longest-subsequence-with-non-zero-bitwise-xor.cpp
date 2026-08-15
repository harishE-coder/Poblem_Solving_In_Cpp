class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        bool hasNonZero = false;
        for(int num : nums) {
            xr ^= num;
            if (num != 0) {
                hasNonZero = true;
            }
        }
        if(xr != 0) return nums.size();
        if(hasNonZero) return nums.size() - 1;
        return 0; 
    }
};