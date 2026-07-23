class Solution {
public:
    void floodFillUtil(vector<vector<int>>& image, int row, int col, int color, int n, int m, int orgColor) {
        image[row][col] = color;

        if(row-1 >= 0 && image[row-1][col] == orgColor) floodFillUtil(image, row-1, col, color, n, m, orgColor);
        if(row+1 < n && image[row+1][col] == orgColor) floodFillUtil(image, row+1, col, color, n, m, orgColor);
        if(col-1 >= 0 && image[row][col-1] == orgColor) floodFillUtil(image, row, col-1, color, n, m, orgColor);
        if(col+1 < m && image[row][col+1] == orgColor) floodFillUtil(image, row, col+1, color, n, m, orgColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // n * m grid
        int n = image.size();
        int m = image[0].size();
        if (image[sr][sc] == color) return image;
        floodFillUtil(image, sr, sc, color, n, m, image[sr][sc]);

        return image;
    }
};