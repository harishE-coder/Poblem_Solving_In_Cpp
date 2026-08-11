class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;

        for (int i = 0; i < grid[0].size(); i++) {
            int row = 0;
            int col = i;
            bool stuck = false;

            while (row < grid.size()) {

                // Ball goes right
                if (grid[row][col] == 1) {
                    if (col + 1 >= grid[0].size() || grid[row][col + 1] == -1) {
                        stuck = true;
                        break;
                    }

                    col++;
                }

                // Ball goes left
                else {
                    if (col - 1 < 0 || grid[row][col - 1] == 1) {
                        stuck = true;
                        break;
                    }

                    col--;
                }

                row++;
            }

            if (stuck)
                ans.push_back(-1);
            else
                ans.push_back(col);
        }

        return ans;
    }
};