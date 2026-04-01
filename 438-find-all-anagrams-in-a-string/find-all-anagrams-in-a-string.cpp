class Solution {
public:
    bool isEqualArray(vector<int> &arr1, vector<int> &arr2) {
        for(int i=0; i<26; i++) {
            if(arr1[i] != arr2[i]) return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n1 = s.length();
        int n2 = p.length();
        if(n2 > n1) return ans;

        vector<int> freqP(26, 0);
        vector<int> freqS(26, 0);

        for(int i=0; i<n2; i++) {
            freqP[p[i]-'a']++;
            freqS[s[i]-'a']++;
        }

        int i;
        for(i=n2; i<n1; i++) {
            if(isEqualArray(freqP, freqS)) ans.push_back(i-n2);
            freqS[s[i-n2]-'a']--;
            freqS[s[i]-'a']++;
        }
        if(isEqualArray(freqP, freqS)) ans.push_back(i-n2);
        return ans;
    }
};