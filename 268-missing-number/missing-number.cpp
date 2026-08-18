class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xr = 0;
        for(int n:nums) xr ^= n;
        for(int i=0;i<=nums.size();i++){
            xr ^= i;
        }
        return xr;
    }
};