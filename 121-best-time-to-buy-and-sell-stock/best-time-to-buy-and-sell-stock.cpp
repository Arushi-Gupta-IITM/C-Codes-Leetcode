class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buyPrice = prices[0];
        int ans = 0;

        for(int i=1; i<n; i++) {
            if(prices[i] < buyPrice) {
                buyPrice = prices[i];
            } else {
                ans = max(ans, prices[i]-buyPrice);
            }
        }
        return ans;
    }
};