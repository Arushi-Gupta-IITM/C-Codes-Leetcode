class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return true;
        return false;
    }
    string reverseVowels(string s) {
        int n = s.length();
        int si = 0, ei = n-1;
        while(si < ei) {
            while(si < n && !isVowel(s[si])) si++;
            while(ei >= 0 && !isVowel(s[ei])) ei--;

            if(si < ei && si < n && ei >= 0) swap(s[si], s[ei]);
            si++;
            ei--;
        }
        return s;
    }
};