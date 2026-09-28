class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num) return false;

            if (board[i][col] == num) return false;

            int r = row - row % 3 + i / 3;
            int c = col - col % 3 + i % 3;
            if (board[r][c] == num) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(board[r][c]=='.'){
                    for(char num='1';num<='9';num++){
                        if(isValid(board,r,c,num)){
                            board[r][c]=num;
                            if(solve(board)) return true;
                            board[r][c]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};