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
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        // exclude current element
        getSubsets(nums, subset, ans, i + 1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> ans;

        getSubsets(nums, subset, ans, 0);
        return ans;
    }
};