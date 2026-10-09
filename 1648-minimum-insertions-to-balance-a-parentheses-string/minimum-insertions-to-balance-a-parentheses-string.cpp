class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0;
        int ans = 0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cnt++;
            } else{
                if(i+1<s.size()&&cnt==0&&s[i+1]==')'){
                    ans++;
                    i++;
                } else if(cnt==0){
                    ans += 2;
                } else if(i+1<s.size()&&cnt!=0&&s[i+1]==')'){
                    i++;
                    cnt--;
                } else if(cnt!=0){
                    ans++;
                    cnt--;
                }
            }
        }
        ans += cnt*2;
        return ans;
    }
};