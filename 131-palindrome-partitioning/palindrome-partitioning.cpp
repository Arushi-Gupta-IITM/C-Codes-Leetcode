class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n-1;

        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void PalindromePartition(string s, vector<vector<string>> &ans, vector<string> &partition) {
        if(s.length() == 0) {
            ans.push_back(partition);
            return;
        }
        for(int size=1; size<=s.length(); size++) {
            string s1 = s.substr(0, size);
            string s2 = s.substr(size);

            if(isPalindrome(s1)) {
                partition.push_back(s1);
                PalindromePartition(s2, ans, partition);
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;

        PalindromePartition(s, ans, partition);
        return ans;
    }
};