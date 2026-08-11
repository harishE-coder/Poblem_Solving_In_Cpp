class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int> ans;
        int row=0;
        int col=0;
        bool upward=true;
        while(ans.size()<m*n){
            ans.push_back(mat[row][col]);
            if(upward){
                if(col == n-1){
                    row++;
                    upward = false;
                } else{
                    if(row==0){
                        col++;
                        upward = false;
                    } else{
                        row--;
                        col++;
                    }
                }
            } else{
                if(row==m-1){
                    col++;
                    upward = true;
                } else{
                    if(col == 0){
                        row++;
                        upward = true;
                    } else{
                        row++;
                        col--;
                    }
                }
            }
        }
        return ans;
    }
};