class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col, int n) {
        if(row == 0) return true;

        // vertical check
        for(int i=0; i<row; i++) {
            if(board[i][col] == 'Q') return false;
        }

        // left diagonal check
        int i = row-1;
        int j = col-1;

        while(i >= 0 && j >= 0) {
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
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
    void nQueens(vector<string> &board, int row, int n, int &ans) {
        if(row == n) {
            ans++;
            return;
        }

        for(int j=0; j<n; j++) {
            if(isSafe(board, row, j, n)) {
                board[row][j] = 'Q';
                nQueens(board, row+1, n, ans);
                board[row][j] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        int ans = 0;

        nQueens(board, 0, n, ans);
        return ans;
    }
};