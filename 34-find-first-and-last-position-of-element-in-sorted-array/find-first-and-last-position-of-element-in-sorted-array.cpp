class Solution {
public:
    int firstPos(vector<int> &nums, int target) {
        int n = nums.size();
        int si = 0;
        int ei = n-1;
        int ans = -1;

        while(si <= ei) {
            int mid = si + (ei-si)/2;
            if(nums[mid] > target) {
                ei = mid-1;
            } else if(nums[mid] < target) {
                si = mid+1;
            } else {
                ans = mid;
                ei = mid-1;
            }
        }
        return ans;
    }
    int lastPos(vector<int> &nums, int target) {
        int n = nums.size();
        int si = 0;
        int ei = n-1;
        int ans = -1;

        while(si <= ei) {
            int mid = si + (ei-si)/2;
            if(nums[mid] > target) {
                ei = mid-1;
            } else if(nums[mid] < target) {
                si = mid+1;
            } else {
                ans = mid;
                si = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        ans.push_back(firstPos(nums, target));
        ans.push_back(lastPos(nums, target));        
        return ans;
    }
};