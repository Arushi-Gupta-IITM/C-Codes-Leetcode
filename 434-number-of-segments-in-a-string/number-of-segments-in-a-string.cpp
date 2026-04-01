class Solution {
public:
    int countSegments(string s) {
        s = s+" ";
        int n = s.length();
        string seg = "";
        int count = 0;

        for(int i=0; i<n; i++) {
            if(s[i] != ' ') {
                seg += s[i];
            } else if(seg.length() != 0){
                count++;
                seg = "";
            }
        }
        return count;
    }
};