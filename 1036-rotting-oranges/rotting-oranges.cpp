class Solution {
public:
    bool allRotten(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) return false;
            }
        }

        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<vector<int>> q;
        int ans = 0;
        // adding rotten oranges in the queue at t = 0
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({0, i, j});
                }
            }
        }

        while(!q.empty()) {
            int t = q.front()[0];
            int i = q.front()[1];
            int j = q.front()[2];
            q.pop();
            ans = max(ans, t);

            // top
            if(i-1 >= 0 && grid[i-1][j] == 1) {
                grid[i-1][j] = 2;
                q.push({t+1, i-1, j});
            }

            // bottom
            if(i+1 < n && grid[i+1][j] == 1) {
                grid[i+1][j] = 2;
                q.push({t+1, i+1, j});
            }

            // left
            if(j-1 >= 0 && grid[i][j-1] == 1) {
                grid[i][j-1] = 2;
                q.push({t+1, i, j-1});
            }

            // right
            if(j+1 < m && grid[i][j+1] == 1) {
                grid[i][j+1] = 2;
                q.push({t+1, i, j+1});
            }
        }

        if(allRotten(grid)) return ans;
        else return -1;
    }
};