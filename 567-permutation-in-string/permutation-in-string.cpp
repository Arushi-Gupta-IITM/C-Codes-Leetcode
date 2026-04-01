class Solution {
public:
    bool isPermutationPresent(string s, vector<int> freq) {
        int n = s.size();
        for(int i=0; i<n; i++) {
            char ch = s[i];
            freq[ch-'a']--;
        }

        for(int i=0; i<26; i++) {
            if(freq[i] != 0) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<int> freq(26, 0);
        for(int i=0; i<n1; i++) {
            char ch = s1[i];
            freq[ch-'a']++;
        }

        for(int i=0; i<(n2-n1+1); i++) {
            string substring = s2.substr(i, n1);
            if(isPermutationPresent(substring, freq)) return true;
        }
        return false;
    }
};