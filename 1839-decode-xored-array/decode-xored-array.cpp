class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        res.push_back(first);
        for(int i:encoded){
            res.push_back(res.back()^i);
        }
        return res;
    }
};