class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lb(n, 0);
        vector<int> rb(n, 0);

        for(int i=1; i<n; i++) {
            lb[i] = max(lb[i-1], height[i-1]);
        }

        for(int i=n-2; i>=0; i--) {
            rb[i] = max(rb[i+1], height[i+1]);
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += max(0, min(lb[i], rb[i])-height[i]);
        }
        return ans;
    }
};