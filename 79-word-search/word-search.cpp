class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>> &vis, string &word, int n, int m, int idx) {
        if(idx == word.length()) return true;
        if(i < 0 || j < 0) return false;
        if(i >= n || j >= m) return false;
        if(vis[i][j] == true) return false;

        if(board[i][j] == word[idx]) {
            vis[i][j] = true;

            if(dfs(i+1, j, board, vis, word, n, m, idx+1)) return true;
            if(dfs(i-1, j, board, vis, word, n, m, idx+1)) return true;
            if(dfs(i, j+1, board, vis, word, n, m, idx+1)) return true;
            if(dfs(i, j-1, board, vis, word, n, m, idx+1)) return true;

            vis[i][j] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int idx = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j] == false && word[idx] == board[i][j]) {
                    if(dfs(i, j, board, vis, word, n, m, idx)) return true;
                }
            }
        }

        return false;
    }
};