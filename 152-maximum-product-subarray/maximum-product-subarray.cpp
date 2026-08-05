class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;

        int prefix = 1;
        int suffix = 1;

        for(int i=0; i<n; i++) {
            prefix = prefix * nums[i];
            ans = max(ans, prefix);

            if(prefix == 0) prefix = 1;
        }

        for(int i=n-1; i>=0; i--) {
            suffix = suffix * nums[i];
            ans = max(ans, suffix);

            if(suffix == 0) suffix = 1;
        }
        return ans;
    }
};