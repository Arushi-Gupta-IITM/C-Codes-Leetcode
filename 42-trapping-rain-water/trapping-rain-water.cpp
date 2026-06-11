class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lb(n);
        vector<int> rb(n);

        // filling left boundry values
        lb[0] = 0;
        for(int i=1; i<n; i++) {
            lb[i] = max(lb[i-1], height[i-1]);
        }
        // filling right boundry values
        rb[n-1] = 0;
        for(int i=n-2; i>=0; i--) {
            rb[i] = max(rb[i+1], height[i+1]);
        }
        // calculating ans  
        int curr = 0;
        int ans = 0;

        for(int i=0; i<n; i++) {
            curr = max(0, min(lb[i], rb[i])-height[i]);
            ans += curr;
        }

        return ans;
    }
};