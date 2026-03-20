class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int freq = 1;
        int curr = nums[0];

        for(int i=1; i<n; i++) {
            if(nums[i] == curr) {
                freq++;
            } else {
                if(freq > n/3) {
                    ans.push_back(curr);
                }
                curr = nums[i];
                freq = 1;
            }
        }

        if(freq > n/3) {
            ans.push_back(curr);
        }
        
        return ans;
    }
};