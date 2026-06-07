class Solution {
public:
    void reverseElements(vector<int> &nums, int start, int end) {
        int i = start, j = end;
        while(i < j) {
            swap(nums[i++], nums[j--]);
        }
    }
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();

        // finding pivot
        int pivot = -1;
        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                pivot = i;
                break;
            }
        }

        if(pivot == -1) { // last permutation: all elements sorted in descending order
            reverseElements(nums, 0, n-1);
            return;
        }

        // finding next greater element than pivot ahead of pivot
        int pos = n-1;
        for(int i=n-1; i>pivot; i--) {
            if(nums[i] > nums[pivot]) {
                pos = i;
                break;
            }
        }

        // swap element at pos at pivot
        swap(nums[pivot], nums[pos]);

        // reverse the elements after the pivot
        reverseElements(nums, pivot+1, n-1);
    }
};