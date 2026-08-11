class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,-1));
        int k=1;
        int r=0,c=0,re=n-1,ce=n-1;
        while(r<=re&&c<=ce){
           for(int i=c;i<=ce;i++){
              ans[r][i]=k;
              k++;
           }   
           for(int i=r+1;i<=re;i++){
             ans[i][ce]=k;
             k++;
           }
           for(int i=ce-1;i>=c;i--){
            if(r==re) break;
              ans[re][i]=k;
              k++;
           }
           for(int i=re-1;i>=r+1;i--){
            if(c==ce) break;
            ans[i][c]=k;
            k++;
           }
           r++;
           c++;
           re--;
           ce--;
        }
     return ans;
    }
};