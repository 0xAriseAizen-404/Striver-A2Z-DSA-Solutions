// https://www.geeksforgeeks.org/problems/infix-to-prefix-notation/1

class Solution {
private:
    int getPriority(char op) {
        if (op == '^') return 3;
        else if (op == '*' || op == '/') return 2;
        else if (op == '+' || op == '-') return 1;
        else return -1;
    }
    string infinixToPostfix(string &s) {
        stack<char> st;
        string postfix = "";
        for (char &x: s) {
            if (('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z') || ('0' <= x && x <= '9'))
                postfix += x;
            else if (x == '(') st.push(x);
            else if (x == ')') {
                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();
            } else {
                if (x == '^') {
                    while (!st.empty() && st.top() != '(' && 
                    getPriority(st.top()) == getPriority(x)) {
                        postfix += st.top();
                        st.pop();
                    }
                } else {
                    while (!st.empty() && st.top() != '(' &&
                    getPriority(st.top()) > getPriority(x)) {
                        postfix += st.top();
                        st.pop();
                    }
                }
                st.push(x);
            }
        }
        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }
        return postfix;
    }
public:
    string infixToPrefix(string &s) {
        // code here
        reverse(s.begin(), s.end());
        // swap brackets
        for (char &c : s) {
            if (c == '(') c = ')';
            else if (c == ')') c = '(';
        }
        string prefix = infinixToPostfix(s);
        reverse(prefix.begin(), prefix.end());
        return prefix;
    }
};
