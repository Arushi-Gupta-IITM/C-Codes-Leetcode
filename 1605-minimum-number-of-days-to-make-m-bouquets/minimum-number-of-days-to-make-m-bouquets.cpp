class Solution {
public:
    bool isValidDay(vector<int> &bloomDay, int m, int k, int maxDays) {
    int bouquets = 0;
    int count = 0;

    for(int i = 0; i < bloomDay.size(); i++) {
        if(bloomDay[i] <= maxDays) {
            count++;
            if(count == k) {
                bouquets++;
                count = 0;
            }
        } else {
            count = 0; 
        }
    }

    return bouquets >= m;
}

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(); // No. of flowers
        long long maxFlowers = 1LL * m * k;
        if(maxFlowers > n) return -1;

        int minDay = INT_MAX;
        int maxDay = INT_MIN;

        for(int i=0; i<n; i++) {
            minDay = min(minDay, bloomDay[i]);
            maxDay = max(maxDay, bloomDay[i]);
        }

        int si = minDay;
        int ei = maxDay;
        int ans = maxDay;

        while(si <= ei) {
            int mid = si + (ei-si)/2;
            if(isValidDay(bloomDay, m, k, mid)) {
                ans = mid; 
                ei = mid-1;
            } else {
                si = mid+1;
            }
        }
        return ans;
    }
};