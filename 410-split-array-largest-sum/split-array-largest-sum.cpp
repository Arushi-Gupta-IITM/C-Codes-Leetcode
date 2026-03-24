class Solution {
public:
    bool isValidSplit(vector<int> &nums, int k, int maxAllowedSum) {
        int n = nums.size();
        int sum = 0;
        int sp = 1;

        for(int i=0; i<n; i++) {
            if(nums[i] > maxAllowedSum) return false;
            if(sum + nums[i] <= maxAllowedSum) {
                sum += nums[i];
            } else {
                sum = nums[i];
                sp++;
            }
        }
        return (sp <= k);
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return -1;

        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += nums[i];
        }

        int si = 0;
        int ei = sum;
        int ans = -1;

        while(si <= ei) {
            int mid = si + (ei-si)/2;
            if(isValidSplit(nums, k, mid)) {
                ans = mid;
                ei = mid-1;
            } else {
                si = mid+1;
            }
        }
        return ans;
    }
};