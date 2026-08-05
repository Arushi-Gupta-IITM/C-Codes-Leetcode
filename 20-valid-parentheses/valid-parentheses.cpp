class Solution {
public:
    bool isValid(string str) {
        int n = str.size();
        stack<char> s;

        for(int i=0; i<n; i++) {
            char ch = str[i];
            if(ch == '(' || ch == '{' || ch == '[') s.push(ch);
            else {
                if(s.empty()) return false;
                if(ch == ')' && s.top() != '(') return false;
                if(ch == ']' && s.top() != '[') return false;
                if(ch == '}' && s.top() != '{') return false;

                s.pop();
            }
        }

        return s.empty() == true;
    }
};