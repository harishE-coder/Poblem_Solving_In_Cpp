class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++){
            int cnt = 0;
            int temp = i;
            while(temp){
            temp &= (temp - 1);
            cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }
};