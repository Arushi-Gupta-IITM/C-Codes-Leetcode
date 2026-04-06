class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans(2); // repeating, missing
        unordered_set<int> s;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(s.find(grid[i][j]) != s.end()) {
                    ans[0] = grid[i][j];
                }
                s.insert(grid[i][j]);
            }
        }

        for(int i=1; i<=n*n; i++) {
            if(s.find(i) == s.end()) {
                ans[1] = i;
                break;
            }
        }
        return ans;
    }
};