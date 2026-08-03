class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // maintaining a priority queue of size k
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int val : nums) {
            pq.push(val);
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};