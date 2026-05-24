class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) {
            if(nums[0] == k) return 1;
            else return 0;
        }
        
        int count = 0;
        int sum = 0;

        for(int i=0; i<n; i++) {
            sum = 0;
            for(int j=i; j<n; j++) {
                sum += nums[j];
                if(sum == k) count++;
            }
        }

        return count;       
    }
};