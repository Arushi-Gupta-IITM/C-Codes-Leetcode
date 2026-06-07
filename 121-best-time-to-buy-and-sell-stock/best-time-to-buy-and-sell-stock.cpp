class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyPrice = prices[0];
        int profit = 0;
        int maxProfit = 0;

        for(int i=1; i<n; i++) {
            if(prices[i] > buyPrice) {
                profit = prices[i] - buyPrice;
                maxProfit = max(profit, maxProfit);
            } else {
                buyPrice = prices[i];
            }
        }

        return maxProfit;
    }
};