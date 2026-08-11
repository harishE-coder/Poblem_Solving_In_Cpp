class Solution {
public:
    static const int Max = 1e6;
    vector<int> res;


    void spf() {
        res.resize(Max + 1);
        for (int i = 0; i <= Max; i++)
            res[i] = i;
        for (int i = 2; i * i <= Max; i++) {
            if (res[i] == i) {
                for (int j = i * i; j <= Max; j += i) {
                    if (res[j] == j)
                        res[j] = i;
                }
            }
        }
    }

    int smallestValue(int n) {
        spf();

        while (true) {
            int sum = 0;
            int x = n;

            while (x > 1) {
                sum += res[x];
                x /= res[x];
            }

            if (sum == n)
                return n;

            n = sum;
        }
    }
};