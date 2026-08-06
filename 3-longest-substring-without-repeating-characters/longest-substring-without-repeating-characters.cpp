class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int st = 0;
        int len = 0;
        int maxLen = 0;
        vector<int> mp(128, -1); // char and its last occurence index

        for(int i=0; i<n; i++) {
            if(mp[s[i]] == -1) {
                len++;
                maxLen = max(len, maxLen);
            } else {
                st = max(mp[s[i]]+1, st);
                len = i-st+1;
                maxLen = max(len, maxLen);
            }
            mp[s[i]] = i;
        }

        return maxLen;
    }
};