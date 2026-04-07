class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++) {
            int si = i+1, ei = n-1;

            while(si < ei) {
                int sum = nums[i] + nums[si] + nums[ei];
                if(sum == 0) {
                    vector<int> list = {nums[i], nums[si], nums[ei]};
                    s.insert(list);

                    si++;
                    ei--;
                } else if(sum > 0) ei--;
                else si++;                
            }
        }

        for(auto list : s) {
            ans.push_back(list);
        }
        return ans;
    }
};