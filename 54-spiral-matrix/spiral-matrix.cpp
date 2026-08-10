class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int top = 0;
        int bottom = n-1;
        int right = m-1;
        int left = 0;
        vector<int> res;
        while(top<=bottom && left<=right){
            for(int j=left;j<=right;j++){
                res.push_back(mat[top][j]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                res.push_back(mat[i][right]);
            }
            right--;
            if(top<=bottom){
            for(int i=right;i>=left;i--){
                res.push_back(mat[bottom][i]);
            }
            bottom--;
            }
            
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    res.push_back(mat[i][left]);
                }
                left++;
            }

        }
        return res;
    }
    
};