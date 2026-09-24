class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row validation 
        for(int i=0; i<9; i++) {
            vector<bool> mp(10, false);
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') continue;

                if(mp[board[i][j]-'0'] == true) return false;
                mp[board[i][j]-'0'] = true;
            }
        }

        // column validation
        for(int j=0; j<9; j++) {
            vector<bool> mp(10, false);
            for(int i=0; i<9; i++) {
                if(board[i][j] == '.') continue;

                if(mp[board[i][j]-'0'] == true) return false;
                mp[board[i][j]-'0'] = true;
            }
        }

        // grid validation
        for(int sr=0; sr<=6; sr+=3) {
            for(int sc=0; sc<=6; sc+=3) {
                vector<bool> mp(10, false);
                for(int i=sr; i<sr+3; i++) {
                    for(int j=sc; j<sc+3; j++) {
                        if(board[i][j] == '.') continue;
                        if(mp[board[i][j]-'0'] == true) return false;
                        mp[board[i][j]-'0'] = true;
                    }
                }
            }
        }

        return true;
    }
};