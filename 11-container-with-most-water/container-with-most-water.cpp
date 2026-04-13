class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int currArea = 0;
        int maxArea = INT_MIN;

        int si = 0, ei = n-1;

        while(si < ei) {
            currArea = (ei-si) * min(nums[si], nums[ei]);
            maxArea = max(maxArea, currArea);

            if(nums[si] < nums[ei]) si++;
            else ei--;
        }

        return maxArea;
    }
};