class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;      
        vector<int> trip(3);
        set<vector<int>> st;
        int tar;

        for(int i=0; i<n; i++) {
            tar = -nums[i];
            int si = i+1, ei = n-1;
            while(si < ei) {
                int sum = nums[si] + nums[ei];
                if(sum == tar) {
                    trip[0] = nums[i];
                    trip[1] = nums[si];
                    trip[2] = nums[ei];
                    st.insert(trip);
                    si++;
                    ei--;
                } else if(sum < tar) {
                    si++;
                } else {
                    ei--;
                }
            }      
            
        }

        for(auto triplet : st) {
            ans.push_back(triplet);
        }

        return ans;
    }
};