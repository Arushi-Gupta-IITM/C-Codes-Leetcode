class Solution {
public:
    void getPerm(vector<vector<int>> &ans, int ind, vector<int> &nums) {
        if(ind == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i=ind; i<nums.size(); i++) {
            swap(nums[ind], nums[i]);
            getPerm(ans, ind+1, nums);

            //backtrack
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> perm;
        getPerm(ans, 0, nums);

        return ans;
    }
};