class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(auto &n:knowledge){
            mp[n[0]] = n[1];
        }
        bool f = false;
        string ans = "";
        string temp = "";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                f=true;
            }
            if(!f){
                ans += s[i];
            }
            if(s[i]==')'){
                f = false;
                if(mp.find(temp)!=mp.end()){
                    ans += mp[temp];
                } else{
                    ans += '?';
                }
                temp = "";
            }
            if(f&&s[i]!='('){
                temp += s[i];
            }
        }
        return ans;
    }
};