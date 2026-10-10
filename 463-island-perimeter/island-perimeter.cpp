class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &vis, int i, int j, int &ans) {
        if(i < 0 || j < 0) return;
        if(i >= grid.size() || j >= grid[0].size()) return;
        if(vis[i][j]) return;
        if(grid[i][j] == 0) return;

        if(i-1 < 0 || grid[i-1][j] == 0) ans++;
        if(i+1 >= grid.size() || grid[i+1][j] == 0) ans++;
        if(j-1 < 0 || grid[i][j-1] == 0) ans++;
        if(j+1 >= grid[0].size() || grid[i][j+1] == 0) ans++;

        vis[i][j] = true;

        dfs(grid, vis, i-1, j, ans);
        dfs(grid, vis, i+1, j, ans);
        dfs(grid, vis, i, j-1, ans);
        dfs(grid, vis, i, j+1, ans);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, vis, i, j, ans);
                }
            }
        }
        return ans;
    }
};