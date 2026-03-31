class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        vector<int> map(26, 0);

        for(int i=0; i<n; i++) {
            char ch = s[i];
            map[ch-'a'] += 1;
        }

        for(int i=0; i<n; i++) {
            char ch = s[i];
            if(map[ch-'a'] == 1) return i;
        }
        return -1;
    }
};