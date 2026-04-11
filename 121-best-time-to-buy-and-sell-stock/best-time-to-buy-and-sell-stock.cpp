class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cp = prices[0];
        int profit = 0, maxProfit = INT_MIN;

        for(int i=0; i<n; i++) {
            if(cp > prices[i]) cp = prices[i];
            if(prices[i] >= cp) {
                profit = prices[i] - cp;
                maxProfit = max(profit, maxProfit);
            }
        }
        return maxProfit;
    }
};