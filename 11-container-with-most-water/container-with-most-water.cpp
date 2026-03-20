class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int curr = 0;
        int maxWater = 0;

        int lp = 0, rp = n-1;

        while(lp < rp) {
            int w = rp - lp;
            int h = min(height[lp], height[rp]);
            curr = w * h;
            maxWater = max(maxWater, curr);

            if(height[lp] < height[rp]) lp++;
            else rp--;
        }

        return maxWater;
    }
};