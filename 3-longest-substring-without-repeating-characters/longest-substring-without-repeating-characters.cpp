class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        int start = 0;
        unordered_map<char, int> map;

        for(int i=0; i<n; i++) {
            if(map.find(s[i]) != map.end() && map[s[i]] >= start) {
                start = map[s[i]] + 1;
            }

            maxLen = max(maxLen, i-start+1);
            map[s[i]] = i;
        }

        return maxLen;
    }
};