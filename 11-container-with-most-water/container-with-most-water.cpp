class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int si = 0;
        int ei = n-1;
        int curr = 0;
        int ans = 0;

        while(si < ei) {
            curr = (ei-si) * min(h[ei], h[si]);
            ans = max(curr, ans);

            if(h[si] < h[ei]) si++;
            else ei--;
        }
        return ans;
    }
};