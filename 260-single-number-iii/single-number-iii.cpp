class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        for(int i:nums){
            xr = xr^i;
        }
        int a=0;
        int b=0;
        unsigned int bit = (unsigned int)xr & -(unsigned int)xr;
        for(int i:nums){
            if(i&bit) a ^= i;
            else b ^= i;
        }
        return {a,b};
    }
};