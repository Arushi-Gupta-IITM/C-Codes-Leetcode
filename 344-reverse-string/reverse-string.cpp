class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int si = 0, ei = n-1;

        while(si < ei) {
            swap(s[si], s[ei]);
            si++;
            ei--;
        }
    }
};