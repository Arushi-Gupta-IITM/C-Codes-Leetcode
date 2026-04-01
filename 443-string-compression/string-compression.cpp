class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        char curr = chars[0];
        int count = 1;
        int in = 0;

        for(int i=1; i<n; i++) {
            if(chars[i] == curr) {
                count++;
            } else {
                if(count == 1) {
                    chars[in] = curr;
                    in++;
                }
                else {
                    chars[in] = curr;
                    in++;
                    string countStr = to_string(count);
                    for(int j=0; j<countStr.length(); j++) {
                        chars[in] = countStr[j];
                        in++;
                    }                   
                }
                curr = chars[i];
                count = 1;
            }
        }
        chars[in] = curr;
        in++;
        if(count > 1) {
            string countStr = to_string(count);
            for(int j=0; j<countStr.length(); j++) {
            chars[in] = countStr[j];
            in++;
            }
        }
        return in;
    }
};