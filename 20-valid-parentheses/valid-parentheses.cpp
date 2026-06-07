class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;

        for(int i=0; i<n; i++) {
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if(st.empty()) return false;
                if(ch == ')' && st.top() != '(') return false;
                if(ch == '}' && st.top() != '{') return false;
                if(ch == ']' && st.top() != '[') return false;

                st.pop();
            }
        }

        return st.empty();
    }
};