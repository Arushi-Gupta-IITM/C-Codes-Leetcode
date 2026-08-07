class Solution {
public:
    int rob(vector<int>& nums) {
       // 0 to n-1 houses, rob house 0 to n-2 and rob houses 1 to n-1, report max of two
       int n = nums.size();
       if(n == 1) return nums[0];
       if(n == 2) return max(nums[0], nums[1]);
       vector<int> dp(n, -1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        int ans = dp[1];

        for(int i=2; i<n-1; i++) {
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }
        ans = dp[n-2];

        fill(dp.begin(), dp.end(), 0);
        dp[1] = nums[1];
        dp[2] = max(nums[2], nums[1]);

        for(int i=3; i<n; i++) {
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
        }
        ans = max(ans, dp[n-1]);
        return ans;
    }
};