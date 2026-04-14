class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int si = 0, ei = n-1;

        while(si <= ei) {
            int mid = si + (ei-si)/2;
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[si] <= nums[mid]) { //left of mid is sorted 
                if(nums[si] <= target && target < nums[mid]) ei = mid-1;
                else si = mid+1;
            } else { //right of mid is sorted
                if(nums[mid] < target && target <= nums[ei]) si = mid+1;
                else ei = mid-1;
            }
        }

        return -1;
    }
};