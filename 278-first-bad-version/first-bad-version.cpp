// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int sv = 1;
        int ev = n;

        if(n == 1){
            if(isBadVersion(1)) return 1;
            else return 0;
        }

        while(sv <= ev) {
            int mid = sv + (ev-sv)/2;
            if(isBadVersion(mid) == false) sv = mid+1;
            else {
                int i = mid-1;
                while(i >= 0) {
                    if(isBadVersion(i) == false) return i+1;
                    i--;
                }

            }
        }
        return 0;
    }
};