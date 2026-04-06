class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> countRow(m);
        vector<int> countCol(n);

        for(int i=0; i<m; i++) {
            countRow[i] = 0;
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 1) countRow[i]++;
            }
        }

        for(int j=0; j<n; j++) {
            countCol[j] = 0;
            for(int i=0; i<m; i++) {
                if(mat[i][j] == 1) countCol[j]++;
            }
        }

        int ans = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 1 && countRow[i] == 1 && countCol[j] == 1) ans++;
            }
        }
        return ans;
    }
};