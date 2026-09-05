class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sm(n,0);
        sm[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            sm[i] = min(sm[i+1],nums[i]);
        }
        // int cnt = 0;
        int big = nums[0];
        for(int i=0;i<n;i++){
            if(big<nums[i]) big = nums[i];
            if(big-sm[i]<=k) return i;
        }
        return -1;
        
    }
};