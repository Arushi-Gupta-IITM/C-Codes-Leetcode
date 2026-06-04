class Solution {
public:

    bool isSafe(vector<string> &board, int row, int col, int n) {
        if(row == 0) return true;

        for(int i=0; i<row; i++) { // vertical check
            if(board[i][col] == 'Q') return false;
        }

        int i = row-1;
        int j = col-1;

        while(i>=0 && j>=0) { // left diagonal check
            if(board[i][j] == 'Q') return false;
            i--; j--;
        }

        i = row-1; 
        j = col+1;

        while(i >= 0 && j < n) {
            if(board[i][j] == 'Q') return false;
            i--;
            j++;
        }

        return true;
    }

    void nQueens(vector<string> &board, vector<vector<string>> &ans, int row, int n) {
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int j=0; j<n; j++) {
            if(isSafe(board, row, j, n)) {
                board[row][j] = 'Q';
                nQueens(board, ans, row+1, n);
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));      
        vector<vector<string>> ans;

        nQueens(board, ans, 0, n);
        return ans;
    }
};