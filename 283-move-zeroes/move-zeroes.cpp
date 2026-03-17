class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int in = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] != 0) {
                nums[in] = nums[i];
                in++;
            }
        }

        for(int i=in; i<n; i++) {
            nums[i] = 0;
        }
    }
};