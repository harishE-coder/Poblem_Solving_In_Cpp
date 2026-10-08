class Solution {
public:
    string removeOuterParentheses(string s) {
        int bal = 0;
        string ss = "";
        for(char c:s){
            if(c==')') bal--;
            if(bal!=0) ss += c;
            if(c=='(') bal++;
            
        }
        return ss;
    }
};