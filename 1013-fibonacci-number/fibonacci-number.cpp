class Solution {
public:
    int fibM(int n, vector<int> &dp) {
        if(n <= 1) {
            dp[n] = n;
            return dp[n];
        }

        if(dp[n] == -1) {
            dp[n] = fibM(n-1, dp) + fibM(n-2, dp);
        }
        return dp[n];
    }
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return fibM(n, dp);
    }
};