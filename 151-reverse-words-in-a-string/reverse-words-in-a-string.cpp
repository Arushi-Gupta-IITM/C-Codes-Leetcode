class Solution {
public:
    string reverseWords(string s) {
        s = " " + s;
        int n = s.length();
        string word = "";
        string ans = "";

        for(int i=n-1; i>=0; i--) {
            if(s[i] != ' ') {
                word = s[i] + word;
            } else {
                if(word.length() > 0) {
                    ans = ans + word + " ";
                    word = "";
                }
            }
        }

        return ans.substr(0, ans.length()-1);
    }
};