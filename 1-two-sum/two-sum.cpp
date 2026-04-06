class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> map;

        for(int i=0; i<n; i++) {
            int complement = target - nums[i];
            if(map.find(complement) != map.end()) {
                ans.push_back(map[complement]);
                ans.push_back(i);
                return ans;
            }
            map[nums[i]] = i;
        }
        return ans;
    }
};