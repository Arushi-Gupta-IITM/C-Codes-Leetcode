class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) {
            if(nums[0] == k) return 1;
            else return 0;
        }
        
        int count = 0;
        unordered_map<int, int> mp; // prefixSum and their frequency
        int ps = 0;        

        for(int i=0; i<n; i++) {
            ps += nums[i];
            int reqSum = ps - k;
            if(reqSum == 0) {
                count++;
            }
            if(mp.find(reqSum) != mp.end()) {
                count += mp[reqSum];
            }
            mp[ps]++;
        } 
        return count;     
    }
};