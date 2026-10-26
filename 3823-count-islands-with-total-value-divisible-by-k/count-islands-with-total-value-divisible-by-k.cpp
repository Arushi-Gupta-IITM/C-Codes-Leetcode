class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &vis, int i, int j, long long &size) {
        if(i < 0 || i >= grid.size()) return;
        if(j < 0 || j >= grid[0].size()) return;
        if(vis[i][j]) return;
        if(grid[i][j] == 0) return;

        size += grid[i][j];
        vis[i][j] = true;

        // visiting the neighbours
        dfs(grid, vis, i-1, j, size);
        dfs(grid, vis, i+1, j, size);
        dfs(grid, vis, i, j-1, size);
        dfs(grid, vis, i, j+1, size);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] != 0 && vis[i][j] == false) {
                    long long size = 0;
                    dfs(grid, vis, i, j, size);
                    if(size%k == 0) ans++;
                } 
            }
        }

        return ans;
    }
};