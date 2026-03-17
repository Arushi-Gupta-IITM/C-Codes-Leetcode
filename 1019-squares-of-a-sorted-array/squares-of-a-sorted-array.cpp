class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        int firstPos = n;

        for(int i=0; i<n; i++) {
            if(nums[i] >= 0) {
                firstPos = i;
                break;
            }
        }

        int i = firstPos;
        int j = firstPos-1;

        while(i<n && j >= 0) {
            int sq1 = nums[i] * nums[i];
            int sq2 = nums[j] * nums[j];

            if(sq1 <= sq2) {
                ans.push_back(sq1); 
                i++;
            } else {
                ans.push_back(sq2);
                j--;
            }
        } 

        while(i < n) {
            ans.push_back(nums[i] * nums[i]);
            i++;
        }

        while(j >= 0) {
            ans.push_back(nums[j] * nums[j]);
            j--;
        }

        return ans;

    }
};