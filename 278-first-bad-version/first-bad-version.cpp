// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int sv = 1;
        int ev = n;

        while(sv < ev) {
            int mid = sv + (ev - sv) / 2;

            if(isBadVersion(mid)) {
                ev = mid;        // possible answer, go left
            } else {
                sv = mid + 1;    // go right
            }
        }
        return sv;
    }
};