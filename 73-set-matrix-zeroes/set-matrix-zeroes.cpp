class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        bool isFirstRow0 = false;
        bool isFirstCol0 = false;

        for(int j=0; j<n; j++) {
            if(mat[0][j] == 0) {
                isFirstRow0 = true;
                break;
            }
        }

        for(int i=0; i<m; i++) {
            if(mat[i][0] == 0) {
                isFirstCol0 = true;
                break;
            }
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        // moving along first row, setting columns 0
        for(int j=1; j<n; j++) {
            if(mat[0][j] == 0) {
                for(int i=1; i<m; i++) {
                    mat[i][j] = 0;
                }
            }
        }
        // moving along first col, setting rows 0
        for(int i=1; i<m; i++) {
            if(mat[i][0] == 0) {
                for(int j=1; j<n; j++) {
                    mat[i][j] = 0;
                }
            }
        }

        // first row 0
        if(isFirstRow0) {
            for(int j=0; j<n; j++) {
                mat[0][j] = 0;
            }
        }
        // first col 0
        if(isFirstCol0) {
            for(int i=0; i<m; i++) {
                mat[i][0] = 0;
            }
        }
    }
};