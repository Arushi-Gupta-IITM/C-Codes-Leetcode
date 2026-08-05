class Solution {
public:
    bool isAlphaNumeric(char ch) {
        if(ch >= 'a' && ch <= 'z') return true;
        if(ch >= 'A' && ch <= 'Z') return true;
        if(ch >= '0' && ch <= '9') return true;

        return false;
    }

    bool isCapital(char ch) {
        if(ch >= 'A' && ch <= 'Z') return true;
        return false;
    }
    bool isPalindrome(string s) {
        string str = "";

        for(int i=0; i<s.length(); i++) {
            char ch = s[i];
            if(isAlphaNumeric(ch)) {
                if(isCapital(ch)) ch = tolower(ch);
                str += ch;
            }
        }

        int si = 0;
        int ei = str.length()-1;

        while(si <= ei) {
            if(str[si] != str[ei]) return false;
            si++;
            ei--;
        }
        return true;
    }
};