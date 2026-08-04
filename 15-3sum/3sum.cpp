class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;

        for(int i=0; i<n; i++) {
            int si = i+1;
            int ei = n-1;

            while(si < ei) {
                if(nums[si] + nums[ei] + nums[i] == 0) {
                    vector<int> trip = {nums[i], nums[si], nums[ei]};
                    s.insert(trip);
                    si++;
                    ei--;
                } else if(nums[si] + nums[ei] + nums[i] > 0) ei--;
                else si++;
            }
        }
        vector<vector<int>> ans;
        for(auto v : s) {
            ans.push_back(v);
        }
        return ans;
    }
};