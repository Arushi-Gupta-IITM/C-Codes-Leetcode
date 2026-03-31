class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        string ans;

        int i=0, j=0;
        while(i<n1 && j<n2) {
            ans += word1[i];
            ans += word2[j];
            i++;
            j++;
        } 
        while(i<n1) {
            ans += word1[i];
            i++;
        }
        while(j<n2) {
            ans += word2[j];
            j++;
        }
        return ans;
    }
};