class Solution {
public:
    int robUtil(vector<int> &nums, vector<int> &dp, int i) {
        if(i == 0) {
            dp[i] = nums[0];
            return dp[i];
        }

        if(i == 1) {
            dp[i] = max(nums[0], nums[1]);
            return dp[i];
        }

        if(dp[i] != -1) return dp[i];

        dp[i] = max(robUtil(nums, dp, i-1), nums[i]+robUtil(nums, dp, i-2));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        // dp[i]: max amount robbed till house i
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n, -1);
        // memoization
        return robUtil(nums, dp, n-1);
    }
};