class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        int m = t[n-1].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // initialization
        dp[0][0] = t[0][0];
        for(int i=1; i<n; i++) {
            dp[i][0] = dp[i-1][0] + t[i][0];
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<i; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + t[i][j];
            }
            dp[i][i] = t[i][i] + dp[i-1][i-1];
        }

        int ans = INT_MAX;
        for(int j=0; j<m; j++) {
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};