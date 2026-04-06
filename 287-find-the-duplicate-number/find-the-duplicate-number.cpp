class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) {
            if(nums[i] == nums[i+1])
            return nums[i];
        }
        return -1;
    }
};