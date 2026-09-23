class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        
        for(int n:nums){
            total += n;
        }
        int target = total - x;
        if (target < 0) return -1;
        int mx = -1;
        int cnt = 0;
        int l = 0;
        for(int r=0;r<nums.size();r++){
            cnt += nums[r];
            while(cnt>target){
                cnt -= nums[l];
                l++;
            }
            if(cnt==target){
                mx = max(mx,r-l+1);
            }
        }
        return mx == -1 ? -1 : nums.size() - mx;
    }
};