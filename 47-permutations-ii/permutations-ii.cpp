class Solution {
public:
    void dfs(vector<int>& nums,vector<int>& temp,vector<int>& visited,vector<vector<int>>& ans){
        if(nums.size()==temp.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i] == nums[i-1] && !visited[i-1]){
                continue;
            }
            if(!visited[i]){
                temp.push_back(nums[i]);
                visited[i] = 1;
                dfs(nums,temp,visited,ans);
                temp.pop_back();
                visited[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        vector<int> visited(nums.size(),0);
        dfs(nums,temp,visited,ans);
        return ans;
    }
};