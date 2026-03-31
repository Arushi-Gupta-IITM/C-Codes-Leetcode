class Solution {
public:
    bool isAlphaNumeric(char ch) {
        if(ch >= 'A' && ch <= 'Z') return true;
        if(ch >= 'a' && ch <= 'z') return true;
        if(ch >= '0' && ch <= '9') return true;

        return false;
    }

    bool isCapital(char ch) {
        if(ch >= 'A' && ch <= 'Z') return true;
        return false;
    }
    bool isPalindrome(string s) {
        int n = s.length();
        int si = 0, ei = n-1;

        while(si <= ei) {
            char ch1 = s[si];
            char ch2 = s[ei];
            if(isAlphaNumeric(ch1) && isAlphaNumeric(ch2)) {
                if(isCapital(ch1)) ch1 = (char)(ch1+32);
                if(isCapital(ch2)) ch2 = (char)(ch2+32);
                if(ch1 != ch2) return false;
                si++;
                ei--;
            } else {
                if(!isAlphaNumeric(ch1)) si++;
                if(!isAlphaNumeric(ch2)) ei--;
            }
        }
       return true;
    }
};