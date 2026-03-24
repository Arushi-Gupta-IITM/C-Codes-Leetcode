class Solution {
public:
    bool isValidWeight(vector<int> &weights, int days, int maxAllowedWeight) {
        int n = weights.size();
        int day = 1;
        int wt = 0;

        for(int i=0; i<n; i++) {
            if(weights[i] > maxAllowedWeight) return false;
            if(wt + weights[i] <= maxAllowedWeight) {
                wt += weights[i];
            } else {
                wt = weights[i];
                day++;
            }
        }

        return (day <= days);
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxWeight = INT_MIN;
        int sum = 0;

        for(int i=0; i<n; i++) {
            maxWeight = max(maxWeight, weights[i]);
            sum += weights[i]; 
        }

        int si = maxWeight;
        int ei = sum;
        int ans = maxWeight;

        while(si <= ei) {
            int mid = si + (ei-si)/2;
            if(isValidWeight(weights, days, mid)) {
                ans = mid;
                ei = mid-1;
            } else {
                si = mid+1;
            }
        }
        return ans;
    }
};