class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;

        for(int i=0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int si = i+1;
            int ei = n-1;

            while(si < ei) {
                int sum = nums[si] + nums[ei] + nums[i];
                if(sum == 0) {
                    vector<int> trip = {nums[i], nums[si], nums[ei]};
                    s.insert(trip);
                    si++;
                    ei--;
                } else if(sum > 0) ei--;
                else si++;
            }

            while(si > i+1 && si < ei && nums[si] == nums[si-1]) si++;
            while(si < ei && ei != n-1 && nums[ei] == nums[ei+1]) ei--;
        }
        vector<vector<int>> ans;
        for(auto v : s) {
            ans.push_back(v);
        }
        return ans;
    }
};