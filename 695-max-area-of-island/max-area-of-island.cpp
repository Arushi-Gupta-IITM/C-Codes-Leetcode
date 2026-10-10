class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &vis, int i, int j, int &currArea) {
        if(i < 0 || j < 0) return;
        if(i >= grid.size() || j >= grid[0].size()) return;
        if(vis[i][j]) return;
        if(grid[i][j] == 0) return;

        currArea++;
        vis[i][j] = true;
        // top
        dfs(grid, vis, i-1, j, currArea);
        // down
        dfs(grid, vis, i+1, j, currArea);
        // left
        dfs(grid, vis, i, j-1, currArea);
        // right
        dfs(grid, vis, i, j+1, currArea);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        int currArea = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1 && vis[i][j] == false) {
                    currArea = 0;
                    dfs(grid, vis, i, j, currArea);
                    ans = max(ans, currArea);
                }
            }
        }

        return ans;
    }
};