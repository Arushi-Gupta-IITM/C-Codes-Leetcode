class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows == 0){
            return ans;
        }
        vector<int> row1 = {1};
        ans.push_back(row1);

        for(int i=2; i<=numRows; i++) {
            vector<int> row;
            for(int j=1; j<=i; j++) {
                if(j == 1 || j == i) {
                    row.push_back(1);
                } else  {
                    row.push_back(ans[i-2][j-2] + ans[i-2][j-1]);
                } 
            }
            ans.push_back(row);
        }

        return ans;
    }
};