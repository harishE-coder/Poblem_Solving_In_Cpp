class Solution {
public:
    int f(vector<vector<int>>& dp, int row, int col,
          vector<vector<int>>& grid) {

        if(row < 0 || col < 0) return INT_MAX;

        if(row == 0 && col == 0) return grid[0][0];

        if(dp[row][col] != -1) return dp[row][col];

        int up = f(dp, row-1, col, grid);
        int left = f(dp, row, col-1, grid);

        return dp[row][col] = grid[row][col] + min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(dp, n-1, m-1, grid);
    }
};