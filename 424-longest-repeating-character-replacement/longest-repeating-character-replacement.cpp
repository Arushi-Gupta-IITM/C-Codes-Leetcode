class Solution {
public:
    int maxFreq(vector<int> &freq) {
        int ans = 0;
        for(int i=0; i<26; i++) {
            ans = max(ans, freq[i]);
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        int l = 0;
        int ans = 0;

        for(int r=0; r<n; r++) {
            freq[s[r]-'A']++;

            while(l <= r && (r-l+1) - maxFreq(freq) > k) {
                freq[s[l]-'A']--;
                l++;
            }

            ans = max(ans, (r-l+1));
        }

        return ans;
    }
};