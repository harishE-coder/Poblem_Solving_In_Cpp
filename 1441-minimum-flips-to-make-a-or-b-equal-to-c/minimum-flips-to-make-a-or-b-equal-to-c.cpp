class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;
        for(int i = 0; i < 32; i++) {
            
        if(((a & 1) == 1 && (b & 1) == 1) && (c & 1) == 0) {
            cnt += 2;
        } else if(((a & 1) | (b & 1)) != (c & 1)){
            cnt++;
        }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return cnt;
    }
};