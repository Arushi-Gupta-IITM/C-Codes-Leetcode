class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        double sum = 0.0;
        double avg = 0.0;
        double th = (double)threshold;
        int ans = 0;

        for(int i=0; i<k; i++) sum += arr[i];
        avg = sum/k;

        if(avg >= th) ans++;

        for(int i=k; i<n; i++) {
            sum = sum + arr[i] - arr[i-k];
            avg = sum / k;
            if(avg >= th) ans++;
        }
        return ans;
    }
};