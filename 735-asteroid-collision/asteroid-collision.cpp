class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int n : asteroids) {

            while (!st.empty() && st.top() > 0 && n < 0) {

                if (abs(st.top()) < abs(n)) {
                    st.pop();
                }
                else if (abs(st.top()) > abs(n)) {
                    n = 0;
                    break;
                }
                else {
                    st.pop();
                    n = 0;
                    break;
                }
            }

            if (n != 0) {
                st.push(n);
            }
        }

        vector<int> res;

        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};