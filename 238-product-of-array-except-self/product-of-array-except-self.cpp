class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        // product = prefix * suffix
        // store prefix product in ans and suffix product in a variable

        ans[0] = 1;
        for(int i=1; i<n; i++) {
            ans[i] = ans[i-1] * nums[i-1];
        }

        int suffix = 1;
        // store suffix from backward direction
        for(int i=n-2; i>=0; i--) {
            suffix = suffix * nums[i+1];
            ans[i] = ans[i] * suffix;
        }

        return ans;
    }
};