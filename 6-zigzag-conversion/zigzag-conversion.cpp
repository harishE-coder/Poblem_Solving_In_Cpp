class Solution {
public:
    string convert(string s, int num) {
        bool f = true;
        int cnt = 0;
        if(num<=1) return s;
        vector<string> res(num);
        for(char i:s){
            res[cnt] += i;
            if(cnt==0){
                f = true;
            } else if(cnt==num-1) f = false;
            cnt += f?+1:-1;
            
            
        }
        string ss ="";
        for(auto a:res){
            for(char n:a) ss += n;
        }
        return ss;
    }
};