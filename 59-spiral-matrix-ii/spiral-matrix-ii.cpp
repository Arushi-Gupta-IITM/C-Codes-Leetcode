class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));
        int num = 1;
        int sr = 0, sc = 0, er = n-1, ec = n-1;

        while(num <= n*n) {
            for(int i=sc; i<=ec; i++) {
                mat[sr][i] = num;
                num++;
            }
            sr++;
            for(int i=sr; i<=er; i++) {
                mat[i][ec] = num;
                num++;
            }
            ec--;
            if(sr <= er) {
                for(int i=ec; i>=sc; i--) {
                mat[er][i] = num;
                num++;
                }
                er--;
            }
            
            if(sc <= ec) {
                for(int i=er; i>=sr; i--) {
                mat[i][sc] = num;
                num++;
                }
                sc++;
            }
        }
        return mat;
    }
};