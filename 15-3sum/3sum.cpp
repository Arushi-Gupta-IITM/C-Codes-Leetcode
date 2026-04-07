class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int si = i+1, ei = n-1;

            while(si < ei) {
                int sum = nums[i] + nums[si] + nums[ei];
                if(sum == 0) {
                    vector<int> list = {nums[i], nums[si], nums[ei]};
                    ans.push_back(list);

                    while(si < ei && nums[si] == nums[si+1]) si++;
                    while(si < ei && nums[ei] == nums[ei-1]) ei--;

                    si++;
                    ei--;
                } else if(sum > 0) ei--;
                else si++;                
            }
        }

        return ans;
    }
};