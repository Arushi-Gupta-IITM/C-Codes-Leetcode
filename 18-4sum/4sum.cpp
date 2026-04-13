class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++) {
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<n; j++) {
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                int si = j+1, ei = n-1;

                while(si < ei) {
                    long long sum = (long long)nums[i] + nums[j] + nums[si] + nums[ei];
                    if(sum < target) si++;
                    else if(sum > target) ei--;
                    else {
                        ans.push_back({nums[i], nums[j], nums[si], nums[ei]});
                        si++;
                        ei--;

                        while(si < ei && nums[si] == nums[si-1]) si++;
                        while(si < ei && nums[ei] == nums[ei+1]) ei--;
                    }
                }
            }
        }

        return ans;
    }
};