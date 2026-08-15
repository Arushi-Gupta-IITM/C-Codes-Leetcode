class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int j=0; j<n; j++) {
            dp[0][j] = mat[0][j];
        }

        for(int i=1; i<n; i++) {
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + mat[i][0];
            dp[i][n-1] = min(dp[i-1][n-1], dp[i-1][n-2]) + mat[i][n-1];

            for(int j=1; j<n-1; j++) {
                dp[i][j] = mat[i][j] + min(dp[i-1][j], min(dp[i-1][j-1], dp[i-1][j+1]));
            }
        }

        int ans = INT_MAX;
        for(int j=0; j<n; j++) {
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};