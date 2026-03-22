class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int si = 0;
        int ei = n-1;

        while(si <= ei) {
            int mid = si + (ei-si)/2;
            if(nums[mid] == target) {
                return mid;
            }

            if(nums[si] <= nums[mid]) { //left dide sorted
                if((nums[mid] > target) && (nums[si] <= target)) {
                    ei = mid-1;
                } else {
                    si = mid+1;
                }
            } else { //right side sorted
                if((nums[mid] < target) && (nums[ei] >= target)) {
                    si = mid+1;
                } else {
                    ei = mid-1;
                }
            }
        }

        return -1;
    }
};