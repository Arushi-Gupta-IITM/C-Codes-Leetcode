class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
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

                    if(sum == tar) {
                        vector<int> list = {nums[i], nums[j], nums[si], nums[ei]};
                        ans.push_back(list);

                        //removing duplicates
                        while(si < ei && nums[si] == nums[si+1]) si++;
                        while(si < ei && nums[ei] == nums[ei-1]) ei--;

                        si++;
                        ei--;
                    } else if(sum < tar) si++;
                    else ei--;
                }
            }
        }
        return ans;
    }
};