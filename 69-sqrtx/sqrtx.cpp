class Solution {
public:
    int mySqrt(int x) {
        int si = 0;
        int ei = x;

        while(si <= ei) {
            int mid = si + (ei-si)/2;
            long long sq = 1LL * mid * mid;
            if(sq == x) return mid;
            else if(sq > x) ei = mid-1;
            else si = mid+1;
        }
        return ei;
    }
};