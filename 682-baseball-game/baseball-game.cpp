class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        vector<int> ans;

        for(int i=0; i<n; i++) {
            string s = operations[i];

            if(s == "C") {
                ans.pop_back();
            } else if(s == "D") {
                ans.push_back(2*ans[ans.size()-1]);
            } else if(s == "+") {
                int sum = ans[ans.size()-1] + ans[ans.size()-2];
                ans.push_back(sum);
            } else {
                int x = stoi(s);
                ans.push_back(x);
            }
        }

        // find sum of ans
        int sum = 0;
        for(int val : ans) {
            sum += val;
        }
        return sum;
    }
};