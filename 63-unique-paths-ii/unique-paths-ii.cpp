class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        // n*m grid
        int n = mat.size();
        int m = mat[0].size();

        if(mat[0][0] == 1 || mat[n-1][m-1] == 1) return 0;

        vector<vector<int>> dp(n, vector<int>(m, 0)); 

        // initialization
        for(int i=0; i<n; i++) { // first column init
            if(mat[i][0] == 1) break; // obstacle
            dp[i][0] = 1;
        }

        for(int j=0; j<m; j++) {
            if(mat[0][j] == 1) break; // obstacle
            dp[0][j] = 1;
        }

        // dp formulation
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(mat[i][j] == 1) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[n-1][m-1];
    }
};