class Solution {
public:
    void floodFillUtil(vector<vector<int>>& image, vector<vector<bool>> &vis, int i, int j, int &col, int &orgCol) {
        int n = image.size();
        int m = image[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m) return;
        if(vis[i][j]) return;
        if(image[i][j] != orgCol) return;

        image[i][j] = col;
        vis[i][j] = true;

        // top
        floodFillUtil(image, vis, i-1, j, col, orgCol);
        // down
        floodFillUtil(image, vis, i+1, j, col, orgCol);
        // left
        floodFillUtil(image, vis, i, j-1, col, orgCol);
        // right
        floodFillUtil(image, vis, i, j+1, col, orgCol);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int orgCol = image[sr][sc];

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        floodFillUtil(image, vis, sr, sc, color, orgCol);
        return image;
    }
};