class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            int curr = nums[i];
            if(curr == 1) {
                count++;
                maxCount = max(count, maxCount);
            } else {
                count = 0;
            }
        }

        return maxCount;
    }
};