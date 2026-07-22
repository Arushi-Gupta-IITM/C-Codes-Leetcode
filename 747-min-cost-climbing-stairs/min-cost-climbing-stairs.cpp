class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // space optimized
        int n = cost.size();
        int last = 0;
        int second = cost[n-1];

        int ans;
        for(int i=n-2; i>=0; i--) {
            ans = cost[i] + min(last, second);

            last = second;
            second = ans;
        }

        return min(last, second);
    }
};