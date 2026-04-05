class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;

        if(m == 1) {
            for(int i=0; i<n; i++) {
                ans.push_back(mat[0][i]);
            }
            return ans;
        }

        if(n == 1) {
            for(int i=0; i<m; i++) {
                ans.push_back(mat[i][0]);
            }
            return ans;
        }

        int sr = 0;
        int sc = 0;
        int er = m-1;
        int ec = n-1;

        while(sr <= er && sc <= ec) {
            for(int i=sc; i<=ec; i++) {
                ans.push_back(mat[sr][i]);
            }
            sr++;

            for(int i=sr; i<=er; i++) {
                ans.push_back(mat[i][ec]);
            }
            ec--;

            if(sr <= er) {
                for(int i=ec; i>=sc; i--) {
                ans.push_back(mat[er][i]);
                }
                er--;
            }
            
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