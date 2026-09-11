class Solution {
public:
    bool isPerfectSquare(int num) {
        int si = 0;
        int ei = num;

        // sqrt of num will have the answer range from 0 to num
        while(si <= ei) {
            int mid = si + (ei-si)/2;
            long long int sq = 1LL * mid * mid;
            if(sq == num) return true;
            else if(sq < num) si = mid+1;
            else ei = mid-1;
        }
        return false;
    }
};