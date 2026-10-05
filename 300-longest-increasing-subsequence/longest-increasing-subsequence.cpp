class Solution {
public:
    int dfs(int idx, int prev, vector<vector<int>>& dp, vector<int>& nums) {
        
        if (idx == nums.size())
            return 0;

        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        // Don't pick
        int notpick = dfs(idx + 1, prev, dp, nums);

        // Pick
        int pick = 0;
        if (prev == -1 || nums[prev] < nums[idx]) {
            pick = 1 + dfs(idx + 1, idx, dp, nums);
        }

        return dp[idx][prev + 1] = max(pick, notpick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return dfs(0, -1, dp, nums);
    }
};