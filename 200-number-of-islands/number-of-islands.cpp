class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>> &vis, int n, int m) {
        if(i >= n || j >= m) return;
        if(i < 0 || j < 0) return;
        if(vis[i][j] == true) return;
        if(grid[i][j] == '0') return;

        vis[i][j] = true;
        dfs(i-1, j, grid, vis, n, m);
        dfs(i+1, j, grid, vis, n, m);
        dfs(i, j-1, grid, vis, n, m);
        dfs(i, j+1, grid, vis, n, m);
    }
    int numIslands(vector<vector<char>>& grid) { // n*m
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1' && vis[i][j] == false) {
                    ans++;
                    dfs(i, j, grid, vis, n, m);
                }
            }
        }

        return ans;
    }
};