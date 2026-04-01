class Solution {
public:
    bool isAnagram(string s1, string s2) {
        vector<int> freq(26, 0);
        for(int i=0; i<s1.length(); i++) {
            freq[s1[i]-'a']++;
        }
        for(int i=0; i<s2.length(); i++) {
            freq[s2[i]-'a']--;
        }

        for(int i=0; i<26; i++) {
            if(freq[i] != 0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n1 = s.length();
        int n2 = p.length();

        string substring = s.substr(0, n2);
        int i;
        for(i=n2; i<n1; i++) {
            if(isAnagram(substring, p)) ans.push_back(i-n2);
            substring.erase(0, 1);
            substring += s[i];
        }
        if(isAnagram(substring, p)) ans.push_back(i-n2);
        return ans;
    }
};