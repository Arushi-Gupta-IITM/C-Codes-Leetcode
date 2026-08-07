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

    int fibT(int n) {
        if(n <= 1) return n;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;

        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

    int fibSO(int n) {
        if(n <= 1) return n;
        int first = 0;
        int sec = 1;
        int ans ;

        for(int i=2; i<=n; i++) {
            ans = first + sec;

            first = sec;
            sec = ans;
        }
        return ans;
    }
    int fib(int n) {
        // vector<int> dp(n+1, -1);
        // return fibM(n, dp);

        return fibSO(n);
    }
};