class Solution {
public:
    void previousSmallerElement(vector<int> &arr, vector<int> &ans) {
        int n = arr.size();
        stack<int> s;

        for(int i=0; i<n; i++) {
            while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();

            if(s.empty()) ans[i] = -1;
            else ans[i] = s.top();
            s.push(i);
        }
    }

    void nextSmallerElement(vector<int> &arr, vector<int> &ans) {
       int n = arr.size();
       stack<int> s; 

       for(int i=n-1; i>=0; i--) {
            while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();

            if(s.empty()) ans[i] = n;
            else ans[i] = s.top();

            s.push(i);
       }
    }
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        int curr = 0;
        int ans = 0;

        vector<int> lb(n); // nearest smaller at left
        vector<int> rb(n); // nearest smaller at right

        nextSmallerElement(h, rb);
        previousSmallerElement(h, lb);

        for(int i=0; i<n; i++) {
            curr = h[i] * (rb[i] - lb[i] - 1);
            ans = max(ans, curr);
        }

        return ans;
    }
};