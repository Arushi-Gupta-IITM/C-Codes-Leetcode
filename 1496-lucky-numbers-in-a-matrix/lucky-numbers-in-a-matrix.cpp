class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> rowMin;
        for(int i=0; i<rows; i++) {
            int minEl = INT_MAX;
            for(int j=0; j<cols; j++) {
                minEl = min(minEl, matrix[i][j]); 
            }
            rowMin.push_back(minEl);
        }

        vector<int> colMax;
        for(int j=0; j<cols; j++) {
            int maxEl = INT_MIN;
            for(int i=0; i<rows; i++) {
                maxEl = max(maxEl, matrix[i][j]);
            }
            colMax.push_back(maxEl);
        }

        vector<int> ans;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j])
                ans.push_back(matrix[i][j]);
            }
        }
        return ans;
    }
};