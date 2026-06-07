class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0 || n == 1) return n;
        unordered_map<char, int> mp;
        int len = 1;
        int ans = 1;
        int start = 0;
        mp[s[0]] = 0;

        for(int i=1; i<n; i++) {
            char ch = s[i];
            if(mp.find(ch) == mp.end()) {
                len++;
                ans = max(len, ans);
                mp[ch] = i;
            } else {
                start = max(mp[ch]+1, start);
                mp[ch] = i;
                len = i-start+1;
                ans = max(len, ans);
            }
        }

        return ans; 
    }
};