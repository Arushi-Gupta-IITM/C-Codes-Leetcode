class Solution {
public:
    bool isValidDivisor(vector<int> &nums, int threshold, int div) {
        int n = nums.size();
        long long ans = 0;
        for(int i=0; i<n; i++) {
            ans += (nums[i]+div-1)/div;
            if(ans > threshold) return false;
        }
        return ans <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxEl = INT_MIN;
        for(int i=0; i<n; i++) {
            maxEl = max(maxEl, nums[i]);
        }

        int si = 1;
        int ei = maxEl;
        int ans = maxEl;

        while(si <= ei) {
            int mid = si + (ei-si)/2;
            if(isValidDivisor(nums, threshold, mid)) {
                ans = mid;
                ei = mid-1;
            } else {
                si = mid+1;
            }
        }
        return ans;
    }
};