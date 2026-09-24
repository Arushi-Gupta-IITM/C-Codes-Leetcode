class Solution {
public:
    int sumOfDigits(int n) {
        int ans = 0;
        while(n > 0) {
            ans += (n%10);
            n = n/10;
        }
        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(nums[i] < 0) continue;
            if(sumOfDigits(nums[i]) == i) return i;
        }
        return -1;
    }
};