class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int freq = 0;
        for(int i=0; i<n; i++) {
            if(freq == 0) {
                ans = nums[i];
            }
            if(nums[i] == ans) freq++;
            else freq--;
        }

        freq = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == ans) {
                freq++;
            }
        }

        if(freq > n/2) return ans;
        return -1;
    }
};