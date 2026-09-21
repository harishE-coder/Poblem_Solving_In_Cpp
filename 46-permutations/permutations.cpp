class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& ans,
             vector<int>& cur, vector<int>& visited) {

        int n = nums.size();

        if (cur.size() == n) {
            ans.push_back(cur);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                visited[j] = 1;
                cur.push_back(nums[j]);

                dfs(nums, ans, cur, visited);

                cur.pop_back();
                visited[j] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        vector<int> visited(nums.size(), 0);

        dfs(nums, ans, cur, visited);

        return ans;
    }
};