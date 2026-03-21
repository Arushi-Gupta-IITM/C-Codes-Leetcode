class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<int> prefix;
        vector<int> suffix;

        prefix.push_back(1);
        for(int i=1; i<n; i++) {
            prefix.push_back(nums[i-1] * prefix.back());
        }

        suffix.push_back(1);
        for(int i=n-2; i>=0; i--) {
            suffix.push_back(nums[i+1] * suffix.back());
        }

        for(int i=0; i<n; i++) {
            ans.push_back(prefix[i] * suffix[n-1-i]);
        }

        return ans;
    }
};