class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, int> mp;

        for(int i=0; i<s.length(); i++) {
            mp[s[i]]++;
        }

        for(int i=0; i<t.length(); i++) {
            if(mp.find(t[i]) == mp.end()) return false;
            else mp[t[i]]--;
        }

        for(auto p : mp) {
            if(p.second != 0) return false;
        }

        return true;
    }
};