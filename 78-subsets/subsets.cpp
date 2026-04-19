class Solution {
public:
    void printSubsets(vector<int> &nums, vector<int> &subset, vector<vector<int>> &ans, int in) {
        if(in == nums.size()) {
            ans.push_back({subset}); // values of subset vector are pushed back as a vector in ans
            return;
        }
        //include
        subset.push_back(nums[in]);
        printSubsets(nums, subset, ans, in+1);

        //backtrack
        subset.pop_back();
        //exclude
        printSubsets(nums, subset, ans, in+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        printSubsets(nums, subset, ans, 0);
        return ans;
    }
};