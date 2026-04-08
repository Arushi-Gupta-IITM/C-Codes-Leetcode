class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == t) return true;
        int n = t.length();
        int si = 0;

        for(int i=0; i<n; i++) {
            char ch = t[i];
            if(ch == s[si]) si++;
            if(si == s.length()) return true;
        }

        return false;
    }
};