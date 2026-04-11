class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        int n = grid.size();
        unordered_set<int> s;
        int a, b;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(s.find(grid[i][j]) == s.end()) {
                    s.insert(grid[i][j]);
                } else {
                    a = grid[i][j];
                }
            }
        }

        for(int i=1; i<=n*n; i++) {
            if(s.find(i) == s.end()) {
                b = i;
                break;
            }
        }

        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};