class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        int in = 0;

        while(i < n) {
            if(nums[i] != val) {
                nums[in] = nums[i];
                i++;
                in++;
            } else {
                i++;
            }
        }
        return in;
    }
};