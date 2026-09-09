class Solution {
public:
    int f(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (row == triangle.size() - 1) {
            return triangle[row][col];
        }
        if (dp[row][col] != 1e9) {
            return dp[row][col];
        }
        int down = f(row + 1, col, triangle, dp);
        int downRight = f(row + 1, col + 1, triangle, dp);
        return dp[row][col] = triangle[row][col] + min(down, downRight);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        return f(0, 0, triangle, dp);
    }
};