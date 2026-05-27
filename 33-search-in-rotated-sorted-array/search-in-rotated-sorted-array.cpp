class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int n = nums.size();
        int si = 0;
        int ei = n-1;

        while(si <= ei) {
            int mid = si + (ei-si)/2;
            if(nums[mid] == tar) return mid;

            if(nums[si] <= nums[mid]) { // left half sorted
                if(nums[si] <= tar && tar < nums[mid]) {
                    ei = mid-1;
                } else {
                    si = mid+1;
                }
            } else { // right half sorted
                if(nums[mid] < tar && tar <= nums[ei]) {
                    si = mid+1;
                } else {
                    ei = mid-1;
                }
            }
        }

        return -1;
    }
};