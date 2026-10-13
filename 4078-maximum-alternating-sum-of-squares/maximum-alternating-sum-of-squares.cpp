class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long int> sq(n, 0);

        for(int i=0; i<n; i++) {
            sq[i] = nums[i] * nums[i];
        }

        sort(sq.begin(), sq.end());

        int si = 0, ei = n-1;
        long long int ans = 0;

        while(si <= ei) {
            if(si == ei) {
                ans += sq[si];
            }
            ans += sq[ei] - sq[si];
            ei--;
            si++;
        }
        return ans;
    }
};