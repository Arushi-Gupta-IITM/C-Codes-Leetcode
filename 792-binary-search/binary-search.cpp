class Solution {
public:
    int binarySearch(vector<int> &nums, int si, int ei, int target) {
        if(si > ei) {
            return -1;
        }
        int mid = si + (ei-si)/2;
        if(nums[mid] == target) {
            return mid;
        } else if(nums[mid] > target) {
            return binarySearch(nums, si, mid-1, target);
        } else {
            return binarySearch(nums, mid+1, ei, target);
        }
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size()-1, target);
    }
};