class Solution {
public:
    bool isvalid(int row,int col,int bal,vector<vector<char>>& grid,vector<vector<vector<int>>>& dp){
        if(grid[row][col]=='(') bal++;
        else bal--;
        if(bal<0) return 0;
        if(dp[row][col][bal]!=-1) return dp[row][col][bal];
        if(row==grid.size()-1&&col==grid[0].size()-1) {
             return bal==0;
        }
        bool down = false,right = false;
        if(col+1<grid[0].size()){
            right = isvalid(row,col+1,bal,grid,dp);
        }
        if(row+1<grid.size()){
            down = isvalid(row+1,col,bal,grid,dp);
        }
        return dp[row][col][bal] = down||right;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int row=grid.size(),col=grid[0].size();
        vector<vector<vector<int>>>dp(row,vector<vector<int>>(col,vector<int>(row+col,-1)));
        return isvalid(0,0,0,grid,dp);
    }
};