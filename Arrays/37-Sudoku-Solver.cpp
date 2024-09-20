class Solution {

private:
    bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
        for(int i = 0 ;i < 9;i++){
            if(board[r][i] == ch) return false;
            if(board[i][c] == ch) return false;

            if(board[ 3*(r/3) + i/3][ 3 * (c/3) + i %3] == ch) return false;
        }
        return true;
    }

    bool canSolveSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {

            for (int col = 0; col < 9; col++) {

                if (board[row][col] == '.') {

                    for (char i = '1'; i <= '9'; i++) {
                        if (isValid(board, row, col, i)) {
                            board[row][col] = i ;
                            if (canSolveSudoku(board))
                                return true;

                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) { canSolveSudoku(board); }
};