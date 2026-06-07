class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = strs[0];
        int ansLen = ans.length();

        for(int i=1; i<n; i++) {
            int pos = min(ans.length(), strs[i].length());
            for(int j=0; j<pos; j++) {
                if(ans[j] != strs[i][j]) {
                    pos = j;
                    break;
                }
            }
            ans = ans.substr(0, pos);
            ansLen = ans.length();
        }

        return ans;
    }
};