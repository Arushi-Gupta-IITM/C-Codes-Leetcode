class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i]: max amount robbed till house i
        int n = nums.size();
        if(n == 1) return nums[0];

        // memory optimization
        int first = nums[0];
        int sec = max(nums[0], nums[1]);
        int ans = sec;

        for(int i=2; i<n; i++) {
            ans = max(sec, first + nums[i]);

            first = sec;
            sec = ans;
        }
        return ans;
    }
};