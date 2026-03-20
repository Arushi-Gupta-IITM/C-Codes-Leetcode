class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        //the numbers that are visited, their indices are marked negative

        for(int i=0; i<n; i++) {
            int idx = abs(nums[i]) - 1;
            if(nums[idx] > 0)
            nums[idx] = -1 * nums[idx];
        }

        vector<int> ans;

        for(int i=0; i<n; i++) {
            if(nums[i] > 0) {
                ans.push_back(i+1);
            }
        }

        return ans;
    }
};