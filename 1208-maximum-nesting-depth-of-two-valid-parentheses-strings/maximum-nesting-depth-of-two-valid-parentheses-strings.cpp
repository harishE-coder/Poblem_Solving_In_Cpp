class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        int deept = 0;
        for(char c:seq){
            if(c=='('){
                deept++;
                ans.push_back(deept%2);
            } else{
                ans.push_back(deept%2);
                deept--;
            }
        }
        return ans;
    }
};