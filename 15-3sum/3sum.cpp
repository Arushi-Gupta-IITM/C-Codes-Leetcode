class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++) {
            if(i>0 && nums[i] == nums[i-1]) continue;
            int tar = -nums[i];
            int si = i+1, ei = n-1;

            while(si < ei) {
                int sum = nums[si] + nums[ei];
                if(sum < tar) si++;
                else if(sum > tar) ei--;
                else {
                    ans.push_back({nums[i], nums[si], nums[ei]});
                    si++;
                    ei--;

                    while(si < ei && nums[si] == nums[si-1]) si++; // si or ei was already updated 
                    while(si < ei && nums[ei] == nums[ei+1]) ei--;
                }
            }
        }

        return ans;
    }
};