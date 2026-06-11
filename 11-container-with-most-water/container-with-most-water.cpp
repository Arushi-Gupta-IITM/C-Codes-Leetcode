class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int si = 0, ei = n-1;
        int area = 0;
        int maxArea = INT_MIN;

        while(si < ei) {
            area = min(height[si], height[ei]) * (ei-si);
            maxArea = max(maxArea, area);

            if(height[si] < height[ei]) si++;
            else ei--;
        }

        return maxArea;
    }
};