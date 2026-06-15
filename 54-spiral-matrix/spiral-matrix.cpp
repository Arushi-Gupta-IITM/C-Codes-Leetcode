class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) { // m*n
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();

        int sr = 0, er = m-1, sc = 0, ec = n-1;

        while(sr <= er && sc <= ec) {

            // right traversal
            for(int j=sc; j<=ec; j++) {
                ans.push_back(mat[sr][j]);
            }
            sr++;
            // down traversal
            for(int i=sr; i<=er; i++) {
                ans.push_back(mat[i][ec]);
            }
            ec--;
            // left traversal
            if(sr <= er) {
                for(int j=ec; j>=sc; j--) {
                ans.push_back(mat[er][j]);
                }
                er--;
            }
            
            //upward traversal
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