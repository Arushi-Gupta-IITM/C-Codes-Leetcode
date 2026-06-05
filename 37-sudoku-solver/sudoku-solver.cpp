class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
        // row check
        for(int j=0; j<9; j++) {
            if(board[row][j] == dig) return false;
        }
        // column check
        for(int i=0; i<9; i++) {
            if(board[i][col] == dig) return false;
        }
        // grid check
        int startRow = (row/3) * 3;
        int startCol = (col/3) * 3;

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[startRow+i][startCol+j] == dig) return false;
            }
        }

        return true;
    }

    bool sudokuSolver(vector<vector<char>>& board, int row, int col) {
        if(row == 9) {
            return true;
        }

        // move past filled cells
        if(board[row][col] != '.') {
            if(col == 8) {
                return sudokuSolver(board, row+1, 0);
            } else {
                return sudokuSolver(board, row, col+1);
            }
        }

        for(char ch='1'; ch<='9'; ch++) {
            if(isSafe(board, row, col, ch)) {
                board[row][col] = ch;
                bool solved;

                if(col == 8) {
                    solved = sudokuSolver(board, row+1, 0);
                } else {
                    solved = sudokuSolver(board, row, col+1);
                }

                if(solved == true) return true;
                board[row][col] = '.';
            } 
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        sudokuSolver(board, 0, 0);
    }
};