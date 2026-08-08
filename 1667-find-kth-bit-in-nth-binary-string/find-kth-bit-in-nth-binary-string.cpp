class Solution {
public:

    string invert(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1')
                s[i] = '0';
            else
                s[i] = '1';
        }

        reverse(s.begin(), s.end());
        return s;
    }

    void res(string &s) {
        // string temp = invert(s);
        s = s + '1' + invert(s);
    }

    char findKthBit(int n, int k) {
        string s = "0";

        while(s.size() < k) {
            res(s);
        }

        return s[k - 1];
    }
};