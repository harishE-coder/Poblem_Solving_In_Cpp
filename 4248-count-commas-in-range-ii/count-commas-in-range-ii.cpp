class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        long long tar = 1000;
        while(n>=tar){
            total += (n-tar+1);
            tar *= 1000;
        }
        return total;
    }
};