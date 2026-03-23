class Solution {
public:
    long long time(vector<int> &piles, int speed) {
        int n = piles.size();
        long long time = 0;
        for(int i=0; i<n; i++) {
            time += (piles[i] + speed - 1)/speed;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxPile = INT_MIN;

        for(int i=0; i<n; i++) {
            maxPile = max(maxPile, piles[i]);
        }

        int start = 1;
        int end = maxPile;
        int ans = maxPile;

        while(start <= end) {
            int mid = start + (end-start)/2;
            long long currTime = time(piles, mid);
            if(currTime > h) {
                start = mid+1;
            } else {
                ans = mid;
                end = mid-1;
            }
        }
        return ans;
    }
};