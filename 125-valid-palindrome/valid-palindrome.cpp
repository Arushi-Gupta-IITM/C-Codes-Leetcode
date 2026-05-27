class Solution {
public:
    bool isAlphaNumeric(char ch) {
        if(ch >= 'a' && ch <= 'z') return true;
        if(ch >= 'A' && ch <= 'Z') return true;
        if(ch >= '0' && ch <= '9') return true;

        return false;
    }
    bool isPalindrome(string s) {
        int n = s.length();
        string str = "";

        for(int i=0; i<n; i++) {
            char ch = s[i];
            if(isAlphaNumeric(ch)) {
                str.push_back((char)tolower(ch));
            }
        }

        int i = 0, j = str.length()-1;

        while(i < j) {
            if(str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};