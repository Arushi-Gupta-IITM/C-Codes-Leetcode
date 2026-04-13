class Solution {
public:
    string reverseWords(string s) {
        s = " " + s;
        int n = s.length();
        string word = "";
        string ans = "";
        int wordLen = 0;

        for(int i=n-1; i>=0; i--) {
           if(s[i] != ' ') {
            wordLen++;
           } else if(wordLen > 0) {
                ans = ans + s.substr(i+1, wordLen) + " ";
                wordLen = 0;
           }
        }

        if(ans.length() > 0)
        return ans.substr(0, ans.length()-1);

        return ans;
    }
};