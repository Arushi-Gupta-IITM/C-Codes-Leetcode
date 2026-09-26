class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char, int> mp;
        int reverse_pos = 26;
        for(char ch='a'; ch<='z'; ch++) {
            mp[ch] = reverse_pos;
            reverse_pos--;
        }

        int ans = 0;
        for(int i=0; i<s.length(); i++) {
            ans += (i+1) * mp[s[i]];
        }
        return ans;
    }
};