class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int si = 0;
        int ei = n-1;

        while(si < ei) {
            int mid = si + (ei - si) / 2;
            if(arr[mid] < arr[mid+1]) {
                si = mid+1;
            } else {
                ei = mid;
            }
        }
        return si;
    }
};