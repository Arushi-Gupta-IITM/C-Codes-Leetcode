class Solution {
public:
    void merge(vector<int> &nums, int si, int mid, int ei) {
        vector<int> arr(ei-si+1);
        int idx = 0;
        int i=si, j=mid+1;

        while(i <= mid && j <= ei) {
            if(nums[i] <= nums[j]) {
                arr[idx++] = nums[i++];
            } else {
                arr[idx++] = nums[j++];
            }
        }

        while(i <= mid) {
            arr[idx++] = nums[i++];
        }

        while(j <= ei) {
            arr[idx++] = nums[j++];
        }

        idx = 0;
        for(int i=si; i<=ei; i++) {
            nums[i] = arr[idx++];
        }
    }
    void sortArrayUtil(vector<int> &nums, int si, int ei) {
        // base case
        if(si >= ei) return ;

        int mid = si + (ei-si)/2;
        sortArrayUtil(nums, si, mid);
        sortArrayUtil(nums, mid+1, ei);

        merge(nums, si, mid, ei);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        sortArrayUtil(nums, 0, n-1);
        return nums;
    }
};