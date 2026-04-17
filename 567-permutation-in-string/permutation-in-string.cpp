class Solution {
public:

    bool isArrayEqual(vector<int> map1, vector<int> map2) {
        for(int i=0; i<26; i++) {
            if(map1[i] != map2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1 > n2) return false;
        vector<int> map1(26, 0);
        vector<int> map2(26, 0);
        
        for(int i=0; i<n1; i++) {
            map1[s1[i]-'a']++;
            map2[s2[i]-'a']++;
        }

        if(isArrayEqual(map1, map2)) return true;

        for(int i=n1; i<n2; i++) {
            map2[s2[i-n1]-'a']--;
            map2[s2[i]-'a']++;

            if(isArrayEqual(map1, map2)) return true;
        }

        return false;
    }
};