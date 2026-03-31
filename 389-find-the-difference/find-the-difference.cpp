class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.length();
        vector<int> map(26, 0);

        for(int i=0; i<n; i++){
            char ch = s[i];
            map[ch-'a'] += 1;
        }

        for(int i=0; i<=n; i++) {
            char ch = t[i];
            map[ch-'a'] -= 1;
        }

        for(int i=0; i<26; i++) {
            if(map[i] != 0) return (char)('a' + i);
        }
        return '\0';
    }
};