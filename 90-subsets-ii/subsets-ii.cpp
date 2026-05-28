class Solution {
public:

    void subsetsWithDupUtil(vector<int> &nums, vector<vector<int>> &ans, vector<int> &subset, int i) {
        if(i == nums.size()) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        subsetsWithDupUtil(nums, ans, subset, i+1);

        subset.pop_back();
        //continuous exclusion of all repeating elements

        int ind = i+1;
        while(ind < nums.size() && nums[ind] == nums[ind-1]) ind++;

        subsetsWithDupUtil(nums, ans, subset, ind);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;

        subsetsWithDupUtil(nums, ans, subset, 0);
        return ans;
    }
};