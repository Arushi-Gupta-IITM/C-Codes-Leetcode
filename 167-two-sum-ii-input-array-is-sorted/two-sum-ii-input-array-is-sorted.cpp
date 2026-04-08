class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        vector<int> ans(2);
        int n = nums.size();

        int si = 0, ei = n-1;
        while(si < ei) {
            int sum = nums[si] + nums[ei];
            if(sum == tar) {
                ans[0] = si+1;
                ans[1] = ei+1;
                break;
            } else if(sum < tar) si++;
            else ei--;
        }

        return ans;
    }
};