class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<int> sqDim(rectangles.size(), 0);
        int maxDim = 0;
        for(int i=0; i<rectangles.size(); i++) {
            maxDim = max(maxDim, min(rectangles[i][0], rectangles[i][1]));
            sqDim.push_back(min(rectangles[i][0], rectangles[i][1]));
        }

        int count = 0;
        for(int i=0; i<sqDim.size(); i++) {
            if(sqDim[i] == maxDim) count++;
        }
        return count;
    }
};