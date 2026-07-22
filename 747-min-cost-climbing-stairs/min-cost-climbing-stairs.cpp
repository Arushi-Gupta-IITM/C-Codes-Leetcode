class Solution {
public:
    void minCost(vector<int>& cost, vector<int> &dp, int i) {
        if(i< 0) return;
        dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        minCost(cost, dp, i-1);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        dp[n-1] = cost[n-1];
        
        minCost(cost, dp, n-2);
        return min(dp[0], dp[1]);
    }
};