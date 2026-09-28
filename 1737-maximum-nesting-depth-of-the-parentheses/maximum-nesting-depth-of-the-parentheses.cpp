class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int currSize = 0;
        int maxSize = 0;

        for(int i=0; i<n; i++) {
            char ch = s[i];

            if(ch == '(') {
                currSize++;
                maxSize = max(maxSize, currSize);
            } 
            if(ch == ')') {
                currSize--;
            }
        }

        return maxSize;
    }
};