class Solution {
public:
    int minSubArrayLen(int tar, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int len = 0;
        int minLen = INT_MAX;
        int l = 0;

        for(int r=0; r<n; r++) {
            sum += nums[r];

            while(sum >= tar && l <= r) {
                len = r-l+1;
                minLen = min(minLen, len);
                sum = sum - nums[l];
                l++;
            }
        }
        if(minLen == INT_MAX) return 0;
        return minLen;
    }
};