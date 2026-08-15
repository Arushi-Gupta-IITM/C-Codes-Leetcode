class Solution {
public:
    int uniquePathsUtil(int i, int j, vector<vector<int>> &dp) {
        if(i == 0 || j == 0) {
            dp[i][j] = 1;
            return dp[i][j];
        }

        if(dp[i][j] == -1) {
            dp[i][j] = uniquePathsUtil(i-1, j, dp) + uniquePathsUtil(i, j-1, dp);
        }
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return uniquePathsUtil(m-1, n-1, dp);
    }
};