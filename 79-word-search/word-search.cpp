class Solution {
public:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, string &word, int idx, int i, int j) {
        if(idx == word.length()) return true;
        if(i < 0 || i >= board.size()) return false;
        if(j < 0 || j >= board[0].size()) return false;
        if(word[idx] != board[i][j]) return false;
        if(vis[i][j] == true) return false;

        vis[i][j] = true;

        // saeching in neighbours
        if(dfs(board, vis, word, idx+1, i+1, j)) return true;
        if(dfs(board, vis, word, idx+1, i-1, j)) return true;
        if(dfs(board, vis, word, idx+1, i, j+1)) return true;
        if(dfs(board, vis, word, idx+1, i, j-1)) return true;

        vis[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int idx = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j] == false) {
                    if(dfs(board, vis, word, idx, i, j)) return true;
                }                
            }
        }
        return false;
    }
};