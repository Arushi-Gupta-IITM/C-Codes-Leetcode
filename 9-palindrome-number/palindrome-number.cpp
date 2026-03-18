class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }

        vector<int> num;

        while(x > 0) {
            int dig = x%10;
            num.push_back(dig);
            x = x/10;
        }

        int n = num.size();

        int si = 0;
        int ei = n-1;
        while(si < ei) {
            if(num[si] != num[ei]) {
                return false;
            }
            si++;
            ei--;
        }

        return true;        
    }
};