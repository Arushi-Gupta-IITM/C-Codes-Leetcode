class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int sr = 0, er = m-1;
        while(sr <= er) {
            int midR = sr + (er-sr)/2;
            if(matrix[midR][n-1] < target) sr = midR+1;
            else if(matrix[midR][0] > target) er = midR-1;
            else {
                int sc = 0, ec = n-1;
                while(sc <= ec) {
                    int midC = sc + (ec-sc)/2;
                    if(matrix[midR][midC] < target) sc = midC + 1;
                    else if(matrix[midR][midC] > target) ec = midC - 1;
                    else {
                        return true;
                    }
                }
                return false;
            }
        }

        return false;
    }
};