class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        // take transpose and reverse rows
        int n = mat.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i < j) swap(mat[i][j], mat[j][i]);
            }
        }

        for(int i=0; i<n; i++) {
            int sc = 0, ec = n-1;
            while(sc < ec) swap(mat[i][sc++], mat[i][ec--]);
        }
    }
};