class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        //store prefix in ans and use a suffix variable
        for(int i=1; i<n; i++) {
            ans[i] = ans[i-1] * nums[i-1];
        }

        long long suffix = 1;
        for(int i=n-2; i>=0; i--) {
            suffix = suffix * nums[i+1];
            ans[i] = ans[i] * suffix;
        }

        return ans;
    }
};