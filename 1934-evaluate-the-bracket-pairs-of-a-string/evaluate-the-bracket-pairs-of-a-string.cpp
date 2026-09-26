class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // storing knowledge in unordered map
        unordered_map<string, string> mp;
        for(int i=0; i<knowledge.size(); i++) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }

        int i = 0;
        while(i < s.length()) {
            char ch = s[i];
            if(ch != '(') {
                i++;
                continue;
            }
            else {
                string key = "";
                int st = i;
                i++;
                while(s[i] != ')') {
                    key += s[i];
                    i++;
                }
                int end = i;
                if(mp.find(key) != mp.end()) {
                    s.replace(st, end-st+1, mp[key]);
                    i = st + mp[key].length()-1;
                } 
                else {
                    s.replace(st, end-st+1, "?"); 
                    i = st+1;
                } 
        }
        }
        return s;
    }
};