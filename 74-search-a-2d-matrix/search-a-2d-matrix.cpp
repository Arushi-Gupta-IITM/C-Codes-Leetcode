class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        // optimal approach, dual binary search
        int n = mat.size();
        int m = mat[0].size();

        int sr = 0, er = n-1;

        while(sr <= er) {
            int midRow = sr + (er-sr)/2;
            if(mat[midRow][0] <= tar && tar <= mat[midRow][m-1]) {
                int si = 0;
                int ei = m-1;
                while(si <= ei) {
                    int mid = si + (ei-si)/2;
                    if(mat[midRow][mid] == tar) return true;
                    if(tar > mat[midRow][mid]) si = mid+1;
                    else ei = mid-1;
                }
                return false;
            } else if(tar > mat[midRow][m-1]) sr = midRow+1;
            else er = midRow-1;
        }
        return false;
    }
};