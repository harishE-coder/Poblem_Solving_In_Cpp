class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int l=0;
        int r=0;
        int mx = 0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            r++;
            while(mp[nums[i]]>k){
                mp[nums[l]]--;
                l++;
            }
            if(r-l>mx) mx = r-l;
        }
        return mx;
    }
};