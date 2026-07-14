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

    int orangesRotting(vector<vector<int>>& grid) { // multi source bfs
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>> q;

        // pushing source into the queue
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) q.push({i, j, 0});
            }
        }

        int ans = 0;
        while(q.size() > 0) {
            int i = q.front()[0];
            int j = q.front()[1];
            int t = q.front()[2];
            ans = max(ans, t);
            q.pop();

            // left
            if(j-1 >= 0 && grid[i][j-1] == 1) {
                grid[i][j-1] = 2;
                q.push({i, j-1, t+1});
            }
            // right
            if(j+1 < m && grid[i][j+1] == 1) {
                grid[i][j+1] = 2;
                q.push({i, j+1, t+1});
            }

            // top
            if(i-1 >= 0 && grid[i-1][j] == 1) {
                grid[i-1][j] = 2;
                q.push({i-1, j, t+1});
            }

            // down
            if(i+1 < n && grid[i+1][j] == 1) {
                grid[i+1][j] = 2;
                q.push({i+1, j, t+1});
            }
        }

        if(allRotten(grid)) return ans;
        return -1;        
    }
};