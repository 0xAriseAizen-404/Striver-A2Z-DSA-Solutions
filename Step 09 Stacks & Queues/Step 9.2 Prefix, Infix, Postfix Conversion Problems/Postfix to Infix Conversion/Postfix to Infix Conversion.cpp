// https://www.geeksforgeeks.org/problems/postfix-to-infix-conversion/1

// User function Template for C++

class Solution {
  public:
    string postToInfix(string &postfix) {
        // Write your code here
        stack<string> st;
        string infix = "";
        for (auto it=postfix.begin(); it!=postfix.end(); ++it) {
            char x = *it;
            if (isalnum(x)) st.push(string(1, x));
            else {
                string op2 = st.top(); st.pop();
                string op1 = st.top(); st.pop();
                st.push("(" + op1 + x + op2 + ")");
            }
        }
        return st.top();
    }
};