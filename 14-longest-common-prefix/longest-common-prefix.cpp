class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = strs[0];

        for(int i=1; i<n; i++) {
            int end = -1;
            for(int j=0; j<min(ans.length(), strs[i].length()); j++) {
                if(strs[i][j] != ans[j]) {
                    end = j;
                    break;
                }
            }
            if(end != -1) {
                ans = ans.substr(0, end);
            } else {
                if(strs[i].length() < ans.length()) ans = strs[i];
            }

            if(ans.length() == 0) return "";
        }
        return ans;
    }
};