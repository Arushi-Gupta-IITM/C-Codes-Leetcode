class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int in = 0;

        int currCount = 1;
        char currChar = chars[0];

        for(int i=1; i<n; i++)
        if(chars[i] == currChar) {
            currCount++;
        } else {
            if(currCount == 1) {
                chars[in] = currChar;
                in++;
            } else {
                chars[in] = currChar;
                in++;
                string countStr = to_string(currCount);
                for(int j=0; j<countStr.length(); j++) {
                    chars[in] = countStr[j];
                    in++;
                }
            }
            currCount = 1;
            currChar = chars[i];
        }



        if(currCount == 1) {
            chars[in] = currChar;
            in++;
        } else {
            chars[in] = currChar;
            in++;
            string countStr = to_string(currCount);
            for(int j=0; j<countStr.length(); j++) {
                chars[in] = countStr[j];
                in++;
            }
        }

        return in;
    }
};