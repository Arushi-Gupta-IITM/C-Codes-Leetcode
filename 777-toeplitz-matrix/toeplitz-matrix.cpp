class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        // if every value is equal to top left neighbour, m*n 
        int m = mat.size();
        int n = mat[0].size();

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(mat[i][j] != mat[i-1][j-1]) return false;
            }
        }

        return true;
    }
};