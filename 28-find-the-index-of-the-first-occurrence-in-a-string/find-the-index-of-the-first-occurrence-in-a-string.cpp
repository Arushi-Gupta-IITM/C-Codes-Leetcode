class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.length();
        int n2 = needle.length();

        if(n2 > n1) return -1;

        string substring = haystack.substr(0, n2);
        if(substring == needle) return 0;

        for(int i=n2; i<n1; i++) {
            substring = substring.substr(1) + haystack[i];
            if(substring == needle) return (i-n2+1);
        }

        return -1;
    }
};