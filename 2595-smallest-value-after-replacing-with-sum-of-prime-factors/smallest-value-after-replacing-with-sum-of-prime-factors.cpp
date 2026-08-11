class Solution {
public:
    int smallestValue(int n) {
        while (true) {
            int sum = 0, num = n, x = num;
            for (int p = 2; p * p <= x; p++) {
                while (x % p == 0) {
                    sum += p;
                    x /= p;
                }
            }
            if (x > 1) sum += x;
            if (sum == n) return n;
            n = sum;
        }
    }
};