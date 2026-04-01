class Solution {
public:
    string reverseWords(string s) {
        s = s + " ";
        int n = s.length();
        string word = "";
        string ans = "";

        for(int i=0; i<n; i++) {
            if(s[i] != ' ') {
                word = word + s[i];
            } else {
                if(word.length() == 0) continue;
                ans = " " + word + ans;
                word = "";
            }
        }
        return ans.substr(1);
    }
};