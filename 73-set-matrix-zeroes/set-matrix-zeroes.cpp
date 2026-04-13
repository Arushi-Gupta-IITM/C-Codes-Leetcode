class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //using first row and first col to store which of them should be set to 0
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRow0 = false;
        bool firstCol0 = false;

        for(int j=0; j<n; j++) {
            if(matrix[0][j] == 0) {
                firstRow0 = true;
                break;
            }
        }

        for(int i=0; i<m; i++) {
            if(matrix[i][0] == 0) {
                firstCol0 = true;
                break;
            }
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1; i<m; i++) {
            if(matrix[i][0] == 0) {
                for(int j=1; j<n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j=1; j<n; j++) {
            if(matrix[0][j] == 0) {
                for(int i=1; i<m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstRow0) {
            for(int j=0; j<n; j++) {
                matrix[0][j] = 0;
            }
        }

        if(firstCol0) {
            for(int i=0; i<m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};