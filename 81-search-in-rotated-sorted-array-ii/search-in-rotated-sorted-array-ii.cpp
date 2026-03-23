class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int si = 0;
        int ei = n-1;

        while(si <= ei) {
            int mid = si + (ei-si)/2;
            if(nums[mid] == target) {
                return true;
            }
            if(nums[si] == nums[mid] && nums[mid] == nums[ei]) {
                si++;
                ei--;
                continue;
            }
            if(nums[si] <= nums[mid]) { //left side sorted
                if(nums[si] <= target && target < nums[mid]) {
                    ei = mid-1;
                } else {
                    si = mid+1;
                }
            } else { //right side sorted
                if(nums[mid] < target && target <= nums[ei]) {
                    si = mid+1;
                } else {
                    ei = mid-1;
                }
            }
        }
        return false;
    }
};