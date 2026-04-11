class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = strs[0];

        for(int i=1; i<n; i++) {
            string s = strs[i];
            int si = 0, ei = min(ans.length(), s.length());

            while(si < ei) {
                if(ans[si] != s[si]) {
                    break;
                }
                si++;
            }
            ans = ans.substr(0, si);            
        }

        return ans;
    }
};