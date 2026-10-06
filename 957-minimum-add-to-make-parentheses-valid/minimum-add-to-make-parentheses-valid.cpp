class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int close = 0;
        int cnt = 0;
        for(char c:s){
            if(c=='(') open++;
            else close++;
            if(open<close){
                open++;
                cnt++;
            } 
        }
        if(open>close) cnt += open - close;
        return cnt;
    }
};