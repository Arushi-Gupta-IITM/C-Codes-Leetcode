class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;

        for(int i=0; i<n; i++) {
            pq.push(nums[i]);
        }

        int step = 1;
        while(!pq.empty()) {
            if(step == k) return pq.top();

            pq.pop();
            step++;
        }
        return -1;
    }
};