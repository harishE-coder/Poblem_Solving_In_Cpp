class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(),nums.end());
        int st = nums[0];
        for(int i=1;i<nums.size();i++){
            st++;
            while(nums[i]>st){
                res.push_back(st);
                st++;
            }
        }
        return res;
    }
};