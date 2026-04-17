class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int si = 0, ei = n-1;

        while(si <= ei) {
            int mid = si + (ei-si)/2;
            if(mid-1 >= si && arr[mid-1] > arr[mid]) ei = mid-1;
            else if(mid+1 <= ei && arr[mid+1] > arr[mid]) si = mid+1;
            else return mid;
        }

        return -1;
    }
};