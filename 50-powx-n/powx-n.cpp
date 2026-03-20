class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1.0) return x;

        long binForm = n;
        if(n < 0) {
            binForm = -1 * binForm;
            x = 1/x;
        }
        double ans = 1;

        while(binForm > 0) {
            int lastDig = binForm % 2;
            if(lastDig == 1) {
                ans = ans * x;
            }
            x = x*x;
            binForm = binForm / 2;
        }

        return ans;    
    }
};