class Solution {
public:
    int f(vector<vector<int>> &dp,int row,int col){
        if(row == 0||col ==0) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        dp[row][col] = f(dp,row,col-1)+f(dp,row-1,col);
        return dp[row][col];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return f(dp,m-1,n-1);
    }
};