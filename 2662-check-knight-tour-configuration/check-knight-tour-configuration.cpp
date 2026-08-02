class Solution {
public:
    void possiblePositions(int i, int j, vector<pair<int, int>> &nextPos) {
        nextPos.push_back({i-1, j-2});
        nextPos.push_back({i-1, j+2});
        nextPos.push_back({i+1, j-2});
        nextPos.push_back({i+1, j+2});

        nextPos.push_back({i-2, j-1});
        nextPos.push_back({i-2, j+1});
        nextPos.push_back({i+2, j-1});
        nextPos.push_back({i+2, j+1});
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return false;
        int n = grid.size();
        if(n == 0) return true;
        unordered_map<int, pair<int, int>> mp;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                mp[grid[i][j]] = {i, j};
            }
        }

        vector<pair<int, int>> nextPos;

        for(int i=0; i<n*n; i++) {
            int row = mp[i].first;
            int col = mp[i].second;

            if(i != 0) {
                bool isValid = false;
                for(int j=0; j<nextPos.size(); j++) {
                    if(row == nextPos[j].first && col == nextPos[j].second) {
                        isValid = true;
                        break;
                    }
                }
                if(isValid == false) return false;
            }
            nextPos.clear();         
            possiblePositions(row, col, nextPos);
        }

        return true;
    }
};