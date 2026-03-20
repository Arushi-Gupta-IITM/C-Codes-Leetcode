class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cost = prices[0];
        int sale = 0;
        int maxSale = 0;

        for(int i=1; i<n; i++) {
            if(prices[i] < cost) {
                cost = prices[i];
            } else {
                sale = prices[i] - cost;
                maxSale = max(sale, maxSale);
            }            
        }

        return maxSale;
    }
};