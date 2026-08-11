class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int len = 0;
        int maxLen = 0;
        int l = 0, r = 0;
        vector<int> map(128, 0);

        for(; r<n; r++) {
            map[s[r]]++;
            if(map[s[r]] > 1) {
                while(map[s[r]] > 1) {
                    map[s[l]]--;
                    l++;
                }
            } else {
                len = r - l + 1;
                maxLen = max(len, maxLen);
            }
        }
        return maxLen;
    }
};