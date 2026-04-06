class Solution {
public:
    bool areMatricesEqual(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }

    vector<vector<int>> rotateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        // transpose matrix and reverse each row
        vector<vector<int>> ans(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                ans[j][i] = mat[i][j];
            }
        }

        for(int i=0; i<n; i++) {
            int sc = 0, ec = n-1;
            while(sc < ec) {
                int temp = ans[i][sc];
                ans[i][sc] = ans[i][ec];
                ans[i][ec] = temp;

                sc++;
                ec--;
            }
        }
        return ans;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int m = target.size();

        for(int i=0; i<4; i++) {
            if(areMatricesEqual(mat, target)) return true;
            mat = rotateMatrix(mat);            
        }
        return false;
    }
};