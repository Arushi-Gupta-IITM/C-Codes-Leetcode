class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int si = 0;
        int ei = n-1;

        while(si <= ei) {
            int mid = si + (ei-si)/2;
            if(nums[mid] < target) {
                si = mid+1;
            } else if(nums[mid] > target) {
                ei = mid-1;
            } else {
                int start = mid;
                for(int i=mid-1; i>=0; i--) {
                    if(nums[i] != target) break;
                    else start = i;
                }
                int end = mid;
                for(int i=mid+1; i<n; i++) {
                    if(nums[i] != target) break;
                    else end = i;
                }
                ans.push_back(start);
                ans.push_back(end);
                return ans;
            }
        }
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
};