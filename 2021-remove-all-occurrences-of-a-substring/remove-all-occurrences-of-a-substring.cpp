class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n2 = part.length();
        int in = 0;

        while(in < s.length()) {
            string substring = s.substr(in, n2);
            if(substring == part) {
                s = s.substr(0, in) + s.substr(in+n2);
                in = max(0, in-n2);
            } else {
                in++;
            }
        }
        return s;
    }
};