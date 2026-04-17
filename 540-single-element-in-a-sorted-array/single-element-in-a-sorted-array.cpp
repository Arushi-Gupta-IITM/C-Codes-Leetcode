class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        int si = 0, ei = n-1;

        while(si <= ei) {
            int mid = si + (ei-si)/2;
            if(mid%2 == 0) {
                if(mid-1 >= 0 && arr[mid] == arr[mid-1]) ei = mid-1;
                else if(mid+1 < n && arr[mid] == arr[mid+1]) si = mid+1;
                else return arr[mid];
            } else {
                if(mid-1 >= 0 && arr[mid] == arr[mid-1]) si = mid+1;
                else if(mid+1 < n && arr[mid] == arr[mid+1]) ei = mid-1;
                else return arr[mid];
            }
        }

        return -1;
    }
};