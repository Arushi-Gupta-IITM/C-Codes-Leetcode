class Solution {
public:
    int fibM(int n, vector<int> &dp)  {
        if(n == 0 || n == 1) {
            dp[n] = n;
            return dp[n];
        }

        if(dp[n] != -1) return dp[n];
        
        dp[n] = fibM(n-1, dp) + fibM(n-2, dp);
        return dp[n];
    } 

    // int fibT() {

    // }

    // int fibSO() {

    // }
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return fibM(n, dp);
    }
};