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
        
        // travel from back and find the element just greater than the pivot
        if(pivot != -1) { // valid pivot, if pivot = -1, array in desc order
            int nextGreatest = 0;
            for(int i=n-1; i>=0; i--) {
                if(nums[i] > nums[pivot]) {
                    nextGreatest = i;
                    break;
                }
            }
            // swap next greatest and pivot element
            swap(nums[pivot], nums[nextGreatest]);
        }

        // reverse the element from pivot+1 till end
        int i = pivot+1, j = n-1;
        while(i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
};