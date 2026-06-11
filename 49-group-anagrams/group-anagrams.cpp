class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(int i=0; i<n; i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            mp[key].push_back(strs[i]);
        }

        for(auto &el : mp) {
            ans.push_back(el.second);
        }

        return ans;
    }
};