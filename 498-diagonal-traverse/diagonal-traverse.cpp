class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;

        int sum = 0;
        int row, col;

        for(int sum = 0; sum <= (m+n-2); sum++) {
            if(sum%2 == 0) { // upward: row--, col++
                row = min(sum, m-1);
                col = sum - row;

                while(row >= 0 && col < n) {
                    ans.push_back(mat[row][col]);
                    row--;
                    col++;
                }
            } else { // downward: row++, col--
                col = min(sum, n-1);
                row = sum - col;

                while(row < m && col >= 0) {
                    ans.push_back(mat[row][col]);
                    row++;
                    col--;
                }
            }
        }

        return ans;
    }
};