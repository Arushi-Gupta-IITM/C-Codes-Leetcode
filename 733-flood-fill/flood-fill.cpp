class Solution {
public:
    void floodFillUtil(int i, int j, int color, vector<vector<int>>& mat, int orgCol, vector<vector<bool>> &vis) {
        int n = mat.size();
        int m = mat[0].size();
        if(i < 0 || i >= n) return;
        if(j < 0 || j >= m) return;
        if(vis[i][j] == true) return;
        if(mat[i][j] != orgCol) return;

        mat[i][j] = color;
        vis[i][j] = true;

        // call for neighbours: top, bottom, left, right
        floodFillUtil(i-1, j, color, mat, orgCol, vis);
        floodFillUtil(i+1, j, color, mat, orgCol, vis);
        floodFillUtil(i, j-1, color, mat, orgCol, vis);
        floodFillUtil(i, j+1, color, mat, orgCol, vis);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& mat, int sr, int sc, int color) {
        int n = mat.size();
        int m = mat[0].size();
        int orgCol = mat[sr][sc];
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        floodFillUtil(sr, sc, color, mat, orgCol, vis);
        return mat;
    }
};