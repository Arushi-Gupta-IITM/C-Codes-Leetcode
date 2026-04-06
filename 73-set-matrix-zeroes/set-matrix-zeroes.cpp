class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        set<pair<int, int>> s;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 0) {
                    s.insert({i, j});
                }
            }
        }

        for(auto p : s) {
            int row = p.first;
            int col = p.second;

            for(int i=0; i<n; i++) {
                mat[row][i] = 0;
            }

            for(int i=0; i<m; i++) {
                mat[i][col] = 0;
            }
        }
    }
};