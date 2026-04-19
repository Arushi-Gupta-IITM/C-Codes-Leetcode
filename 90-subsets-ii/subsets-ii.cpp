class Solution {
public:
    void getSubsets(vector<int> &nums, vector<int> &subset, vector<vector<int>> &ans, int i) {
        if(i == nums.size()) {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        getSubsets(nums, subset, ans, i + 1);
        subset.pop_back();

        // skip duplicates
        int idx = i+1;
        while (idx < nums.size() && nums[idx] == nums[idx-1]) {
            idx++;
        }

        // exclude current element
        getSubsets(nums, subset, ans, idx);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> ans;

        getSubsets(nums, subset, ans, 0);
        return ans;
    }
};