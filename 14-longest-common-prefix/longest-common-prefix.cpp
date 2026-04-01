class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string prefix = strs[0];

        for(int i=1; i<n; i++) {
            string curr = strs[i];
            for(int j=0; j<min(curr.length(), prefix.length()); j++) {
                if(prefix[j] != curr[j]) {
                    prefix = prefix.substr(0, j);
                }
            }
            if(curr.length() < prefix.length()) {
                prefix = curr;
            }
        }
        return prefix;

    }
};