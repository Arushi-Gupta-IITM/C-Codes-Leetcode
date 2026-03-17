class Solution {
public:
    int noOfDigits(int num) {
        int digits = 0;
        while(num > 0) {
            digits++;
            num = num/10;
        }
        return digits;
    }
    
    int findNumbers(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            int curr = nums[i];
            if(noOfDigits(curr)%2 == 0) {
                count++;
            }
        }

        return count;
    }
};