class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int min) {
        int n = c.size();
        int sat = 0;
        int maxSat = 0;
        // first satisy unsatisfied customers using technique, then add satisfied customers
        for(int i=0; i<min; i++) {
            if(g[i] == 1) sat += c[i];
        }
        maxSat = max(maxSat, sat);

        for(int i=min;i<n; i++) {
            if(g[i] == 1) sat += c[i];
            if(g[i-min] == 1) sat -= c[i-min];
            maxSat = max(maxSat, sat);
        }

        // add satisfied customers
        for(int i=0; i<n; i++) {
            if(g[i] == 0) maxSat += c[i];
        }
        return maxSat;
    }
};