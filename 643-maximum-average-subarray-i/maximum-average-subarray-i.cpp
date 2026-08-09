class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum = 0.0;
        double avg = 0.0;
        double ans = INT_MIN;

        for(int i=0; i<k; i++) {
            sum += nums[i];
        }
        avg = sum / k;
        ans = max(ans, avg);

        for(int i=k; i<n; i++) {
            sum = sum + nums[i] - nums[i-k];
            avg = sum / k; 
            ans = max(ans, avg);
        }
        return ans;
    }
};