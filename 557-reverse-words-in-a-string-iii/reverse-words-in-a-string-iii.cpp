class Solution {
public:
    string reverseWords(string s) {
        s = s + " ";
        int n = s.length();
        string ans;
        string word;

        for(int i=0; i<n; i++) {
            char ch = s[i];
            if(ch == ' ') {
                ans = ans + word + ' ';
                word = "";
            } else {
                word = ch + word;
            }
        }
        ans = ans.substr(0, ans.length()-1);
        return ans;
    }
};