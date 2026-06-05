class Solution {
public:
    void combinationSumUtil(vector<int>& arr, vector<vector<int>> &ans, vector<int> &comb, int i, int tar) {        
        if(tar == 0) {
            ans.push_back(comb);
            return;
        }

        if(i < 0) {
            return;
        }
        
        
        if(arr[i] <= tar) {
            // include current element
            comb.push_back(arr[i]);
            combinationSumUtil(arr, ans, comb, i, tar-arr[i]);

            //backtrack
            comb.pop_back();            
        }
        
        // exclude current element
        combinationSumUtil(arr, ans, comb, i-1, tar);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        int n = arr.size();
        combinationSumUtil(arr, ans, comb, n-1, target);
        return ans;
    }
};