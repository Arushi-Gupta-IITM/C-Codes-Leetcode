class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        bool firstRow0 = false;
        bool firstCol0 = false;

        for(int j=0; j<m; j++) {
            if(mat[0][j] == 0) {
                firstRow0 = true;
                break;
            }
        }

        for(int i=0; i<n; i++) {
            if(mat[i][0] == 0) {
                firstCol0 = true;
                break;
            }
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        // checking first row
        for(int j=1; j<m; j++) {
            if(mat[0][j] == 0) {
                for(int i=1; i<n; i++) mat[i][j] = 0;
            }
        }

        // checking first column
        for(int i=1; i<n; i++) {
            if(mat[i][0] == 0) {
                for(int j=1; j<m; j++) mat[i][j] = 0;
            }
        }

        if(firstRow0) {
            for(int j=0; j<m; j++) mat[0][j] = 0;
        }

        if(firstCol0) {
            for(int i=0; i<n; i++) mat[i][0] = 0;
        }
    }
};