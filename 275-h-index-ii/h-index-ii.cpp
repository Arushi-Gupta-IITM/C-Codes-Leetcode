class Solution {
public:
    int hIndex(vector<int>& cit) {
        int n = cit.size();
        int si = 0, ei = n-1;
        int ans = 0;
        int pap = 1;

        for(int i=n-1; i>=0; i--) {
            if(cit[i] >= pap) {
                ans = pap;
                pap++;
            } else break;
        }

        return ans;
    }
};