class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        //transpose of matrix in place
        for(int i=0; i<m; i++) {
            for(int j=i+1; j<n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        //reverse the rows
        for(int i=0; i<m; i++) {
            int si = 0, ei = n-1;
            while(si < ei) {
                swap(mat[i][si], mat[i][ei]);
                si++;
                ei--;
            }
        }
    }
};