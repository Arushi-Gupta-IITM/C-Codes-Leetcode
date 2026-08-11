class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int count0 = 0;
        int len = 0;
        int maxLen = 0;
        int r = 0;

        for(; r<n; r++) {
            if(nums[r] == 0) count0++;

            if(count0 > k) {
                if(nums[l] == 0) count0--;
                l++;
            } else {
                len = r - l + 1;
                maxLen = max(len, maxLen);
            }
        }
        // maxLen = max(maxLen, r-l+1);
        return maxLen;
    }
};