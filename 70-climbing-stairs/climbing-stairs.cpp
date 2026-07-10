class Solution {
public:
    int climb(int n, vector<int> &dp) {
        if(n == 0 || n == 1) {
            dp[n] = 1;
            return dp[n];
        }

        if(dp[n] == 0) {
            dp[n] = climb(n-1, dp) + climb(n-2, dp);
        }

        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        return climb(n, dp);        
    }
};