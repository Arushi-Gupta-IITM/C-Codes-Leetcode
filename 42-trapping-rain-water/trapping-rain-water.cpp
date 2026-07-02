class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int l = 0, r = n - 1;
        int lmax = 0, rmax = 0;

        int ans = 0;
        while (l <= r) {
            lmax = max(h[l], lmax);
            rmax = max(h[r], rmax);

            if (lmax < rmax) {
                ans += lmax - h[l];
                l++;
            } else {
                ans += rmax - h[r];
                r--;
            }
        }
        return ans;
    }
};