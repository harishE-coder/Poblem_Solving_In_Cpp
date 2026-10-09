class Solution {
public:
    int minInsertions(string s) {
        stack<int> st;
        int ans = 0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(0);
            } else{
                if(i+1<s.size()&&st.empty()&&s[i+1]==')'){
                    ans++;
                    i++;
                } else if(st.empty()){
                    ans += 2;
                } else if(i+1<s.size()&&!st.empty()&&s[i+1]==')'){
                    i++;
                    st.pop();
                } else if(!st.empty()){
                    ans++;
                    st.pop();
                }
            }
        }
        ans += st.size()*2;
        return ans;
    }
};