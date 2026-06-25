// https://www.geeksforgeeks.org/problems/prefix-to-postfix-conversion/1

class Solution {
public:
    string preToPost(string &prefix) {
        stack<string> st;
        string postfix;
        for (auto it=prefix.rbegin(); it!=prefix.rend(); it++) {
            char x = *it;
            if (isalnum(x)) st.push(string(1, x));
            else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                st.push(op1 + op2 + x);
            }
        }
        return st.top();
    }
};