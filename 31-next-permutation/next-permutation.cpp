class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return;
        
        int pivot = -1;
        // find pivot, 
        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                pivot = i;
                break;
            }
        }
        if(pivot == -1) { // array sorted in descending order
            sort(nums.begin(), nums.end());
            return;
        }
        // travel from back and find the element just greater than the pivot
        int nextGreatest = 0;
        for(int i=n-1; i>=0; i--) {
            if(nums[i] > nums[pivot]) {
                nextGreatest = i;
                break;
            }
        }

        // swap next greatest and pivot element
        swap(nums[pivot], nums[nextGreatest]);

        // sort element from pivot+1 till end in ascending order
        sort(nums.begin()+pivot+1, nums.end());
    }
};