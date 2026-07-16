class Solution {
public:
    void floodFillUtil(vector<vector<int>>& image, vector<vector<bool>>& vis, int &org, int &color, int i, int j) {
        int n = image.size();
        int m = image[0].size();
        if(i < 0 || j < 0) return;
        if(i >= n || j >= m) return;
        if(vis[i][j]) return;
        if(image[i][j] != org) return;

        vis[i][j] = true;
        image[i][j] = color;

        // call for neighbours
        floodFillUtil(image, vis, org, color, i-1, j);
        floodFillUtil(image, vis, org, color, i+1, j);
        floodFillUtil(image, vis, org, color, i, j-1);
        floodFillUtil(image, vis, org, color, i, j+1);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org = image[sr][sc]; // n*m grid
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        floodFillUtil(image, vis, org, color, sr, sc);

        return image;
    }
};