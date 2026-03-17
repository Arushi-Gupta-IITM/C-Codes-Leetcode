class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int i = n-2;
        int count = 1;

        while(i >= 0) {
            if(nums[i] != nums[i+1]) {
                count++;
                if(count == 3) {
                    return nums[i];
                }
            }
            i--;
        }

        return nums[n-1];
    }
};