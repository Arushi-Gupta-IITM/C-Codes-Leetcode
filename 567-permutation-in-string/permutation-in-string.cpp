class Solution {
public:
    bool isSameArray(vector<int> arr1, vector<int> arr2) {
        int n = arr1.size();
        for(int i=0; i<n; i++) {
            if(arr1[i] != arr2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if(n1 > n2) return false;

        vector<int> freq(26, 0);
        for(int i=0; i<n1; i++) {
            char ch = s1[i];
            freq[ch-'a']++;
        }

        vector<int> winFreq(26, 0);
        for(int i=0; i<n1; i++) {
            winFreq[s2[i]-'a']++;
        }

        int in = n1;
        while(in < n2) {
            if(isSameArray(freq, winFreq)) return true;
            char ch = s2[in];
            winFreq[ch-'a']++;
            winFreq[s2[in-n1]-'a']--;
            in++;
        }
        return isSameArray(freq, winFreq);
    }
};