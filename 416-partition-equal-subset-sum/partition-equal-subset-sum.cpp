class Solution {
public:
    int canPartitionUtil(vector<int> &nums, int n, int tar, vector<vector<int>> &dp) {
        if(tar == 0) return 1;
        if(n == 0) return 0;
        
        if(dp[n][tar] != -1) return dp[n][tar];

        int exclude = canPartitionUtil(nums, n-1, tar, dp); 

        if(nums[n-1] <= tar) {
            int include = canPartitionUtil(nums, n-1, tar-nums[n-1], dp);          
            if(include == 1 || exclude == 1) dp[n][tar] = 1;
            else dp[n][tar] = 0;
        } else {
            dp[n][tar] = exclude;
        }

        return dp[n][tar];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int val : nums) sum += val;

        if(sum%2 == 1) return false;

        int tar = sum/2;
        
        vector<vector<int>> dp(n+1, vector<int>(tar+1, -1));
        // -1: not calculated, 0: no/false, 1: yes/true
        for(int j=1; j<=tar; j++) {
            dp[0][j] = 0;
        }

        for(int i=0; i<=n; i++) {
            dp[i][0] = 1;
        }
        if (canPartitionUtil(nums, n, tar, dp) == 1) return true;
        else return false;
    }
};