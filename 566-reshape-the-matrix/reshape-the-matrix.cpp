class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size();
        int col = mat[0].size();

        if(r*c != row*col) return mat;

        int i=0, j=0;
        vector<vector<int>> ans(r, vector<int>(c));

        for(int k=0; k<r; k++) {
            for(int l=0; l<c; l++) {
                ans[k][l] = mat[i][j];
                if(j == col-1) {
                    i++;
                    j = 0;
                } else {
                    j++;
                }
            }
        }
        return ans;
    }
};