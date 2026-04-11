class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        for(char ch : s) {
            if(isalnum(ch)) {
                ans += tolower(ch);
            }
        }

        int si = 0, ei = ans.length()-1;
        while(si < ei) {
            if(ans[si] != ans[ei]) return false;
            si++;
            ei--;
        }
        return true;
    }
};