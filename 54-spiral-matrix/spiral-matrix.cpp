class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;

        int sr = 0, sc = 0, er = n-1, ec = m-1;
        while(sr <= er && sc <= ec) {
            // top
            for(int j=sc; j<=ec; j++) {
                ans.push_back(mat[sr][j]);
            }
            sr++;
            // right
            for(int i=sr; i<=er; i++) {
                ans.push_back(mat[i][ec]);
            }
            ec--;
            // bottom
            if(sr <= er) {
                for(int j=ec; j>=sc; j--) {
                    ans.push_back(mat[er][j]);
                }
                er--;
            }
            
            // left
            if(sc <= ec) {
                for(int i=er; i>=sr; i--) {
                    ans.push_back(mat[i][sc]);
                }
                sc++;
            }            
        }

        return ans;
    }
};