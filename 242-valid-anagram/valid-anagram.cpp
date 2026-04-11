class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();

        if(n1 != n2) return false;
        vector<int> map(26, 0);

        for(int i=0; i<n1; i++) {
            int in = s[i] - 'a';
            map[in]++;
        }

        for(int i=0; i<n2; i++) {
            int in = t[i] - 'a';
            map[in]--;
        }

        for(int i=0; i<26; i++) {
            if(map[i] != 0) return false;
        }

        return true;
    }
};