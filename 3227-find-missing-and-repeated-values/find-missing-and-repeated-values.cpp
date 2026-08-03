class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<bool> vis(n*n+1, false);

        int repeat = -1;
        int miss = -1;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(vis[grid[i][j]]) repeat = grid[i][j];
                else vis[grid[i][j]] = true; 
            }
        }

        for(int i=1; i<=n*n; i++) {
            if(vis[i] == false) miss = i;
        }

        vector<int> ans;
        ans.push_back(repeat);
        ans.push_back(miss);

        return ans;
    }
};