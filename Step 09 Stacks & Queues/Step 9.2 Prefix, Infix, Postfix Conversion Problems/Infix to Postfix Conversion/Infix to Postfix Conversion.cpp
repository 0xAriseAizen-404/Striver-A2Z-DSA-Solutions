// https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1

class Solution {
private:
    int getPriority(char op) {
        if (op == '^') return 3;
        else if (op == '*' || op == '/') return 2;
        else if (op == '+' || op == '-') return 1;
        else return -1;
    }
public:
    string infixToPostfix(string& s) {
        // code here
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
                st.pop();
            } else {
                if (x == '^') {
                    // right-associative
                    while (!st.empty() && 
                    getPriority(st.top()) == getPriority(x)) {
                        break;
                    } // No need of this condition
                    st.push(x);
                } else {
                    // left-associative
                    while (!st.empty() &&
                    getPriority(st.top()) >= getPriority(x)) {
                        postfix += st.top();
                        st.pop();
                    }
                    st.push(x);
                }
            }
        }
        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }
        return postfix;
    }
};