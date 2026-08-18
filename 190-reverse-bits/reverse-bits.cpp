class Solution {
public:
    int reverseBits(int n) {
        bitset<32> bt(n);
        string s= bt.to_string();
        reverse(s.begin(),s.end());
        bitset<32> rev(s);
    return (int)rev.to_ulong();
    }
};