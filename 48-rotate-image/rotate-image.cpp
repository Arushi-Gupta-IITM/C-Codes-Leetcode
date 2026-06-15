class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        // standard logic: transpose of matrix in palce and then reverse the rows, n*m matrix
        int n = mat.size();
        int m = mat[0].size();

        // transpose of matrix in place
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i > j) {
                    swap(mat[i][j], mat[j][i]);
                }
            }
        }

        // reverse each row
        for(int i=0; i<n; i++) {
            int si = 0, ei = m-1;
            while(si < ei) {
                swap(mat[i][si++], mat[i][ei--]);
            }
        }
    }
};