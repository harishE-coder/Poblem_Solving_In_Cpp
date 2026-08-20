class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ps(arr.size());
        ps[0] = arr[0];
        for(int i=1;i<arr.size();i++){
            ps[i] = ps[i-1]^arr[i];
        }
        vector<int> res;
        for(auto i:queries){
            if(i[0]!=0){
            res.push_back(ps[i[0]-1]^ps[i[1]]);
            }
            else if(i[0]==0){
                res.push_back(ps[i[1]]);
            }
        }
        return res;
    }
};