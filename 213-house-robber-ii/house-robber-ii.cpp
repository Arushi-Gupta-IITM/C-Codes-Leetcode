class Solution {
public:
    int rob(vector<int>& cost) {
        int n = cost.size();
        int ans = 0;

        if(n == 0) return 0;
        if(n == 1) return cost[0];

        // robbing from house 0 to n-2
        vector<int> dp(n, 0);
        dp[0] = 0;
        dp[1] = cost[0];

        for(int i=2; i<n; i++) {
            dp[i] = max(dp[i-1], cost[i-1]+dp[i-2]);
        }

        ans = max(ans, dp[n-1]);

        // robbing house from 1 to n-1
        dp[0] = 0;
        dp[1] = cost[1];

        for(int i=2; i<n; i++) {
            dp[i] = max(dp[i-1], cost[i]+dp[i-2]);
        }

        ans = max(ans, dp[n-1]);
        return ans;
    }
};