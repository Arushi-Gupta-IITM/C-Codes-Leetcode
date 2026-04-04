class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }

        int revNum = 0; 
        int copy = x;
        while(x != 0) {
            int dig = x%10;
            if(revNum > INT_MAX/10 || revNum < INT_MIN/10) return false;
            revNum = revNum*10 + dig;
            x = x/10;
        }  
        return copy == revNum;    
    }
};