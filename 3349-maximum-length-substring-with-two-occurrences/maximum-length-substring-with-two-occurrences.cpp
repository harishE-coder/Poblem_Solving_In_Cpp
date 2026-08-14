class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int,int> mp;
        int l =0;
        int r= 0;
        int mx = 0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            r++;
            while(mp[s[i]]>2){
                mp[s[l]]--;
                l++;
            }
            mx = max(mx,r-l);
        }
        return mx;
    }
};