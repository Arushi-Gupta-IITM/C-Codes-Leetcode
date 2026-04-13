class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        if(n == 0) return intervals;
        ans.push_back(intervals[0]);

        for(int i=1; i<n; i++) {
            if(intervals[i][0] <= ans.back()[1]) { //merge
                int first = ans.back()[0];
                int last = max(intervals[i][1], ans.back()[1]);
                ans.pop_back();
                ans.push_back({first, last});
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};