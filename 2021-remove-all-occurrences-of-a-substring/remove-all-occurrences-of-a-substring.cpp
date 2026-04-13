class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n2 = part.length();
    
        while((s.find(part) < s.length()) && (s.length() > 0)) {
            s.erase(s.find(part), n2);
        }
        return s; 
    }
};