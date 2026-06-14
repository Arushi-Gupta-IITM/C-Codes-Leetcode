class Solution {
public:
    void combinationSumUtil(vector<int> &arr, vector<vector<int>> &ans, vector<int> &comb, int tar, int i) {
        // base case
        if(tar == 0) {
            ans.push_back(comb);
            return;
        }

        if(i == arr.size()) return;

        if(arr[i] <= tar)  { // given arr[i] element are positive
            // include current element
            comb.push_back(arr[i]);
            combinationSumUtil(arr, ans, comb, tar-arr[i], i);
            comb.pop_back();
        } 

        // exclude current element
        combinationSumUtil(arr, ans, comb, tar, i+1); 
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        combinationSumUtil(arr, ans, comb, target, 0);
        return ans;
    }
};