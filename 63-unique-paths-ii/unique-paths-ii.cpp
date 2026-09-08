class Solution {
public:
    int f(vector<vector<int>>& dp, int row, int col,
          vector<vector<int>>& obstacleGrid) {

        if(row < 0 || col < 0) return 0;

        if(obstacleGrid[row][col] == 1) return 0;

        if(row == 0 && col == 0) return 1;

        if(dp[row][col] != -1) return dp[row][col];

        return dp[row][col] =
            f(dp,row-1,col,obstacleGrid) +
            f(dp,row,col-1,obstacleGrid);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n,-1));

        return f(dp,m-1,n-1,obstacleGrid);
    }
};