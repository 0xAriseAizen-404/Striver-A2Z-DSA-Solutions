// https://www.geeksforgeeks.org/problems/prefix-to-infix-conversion/1

class Solution {
  public:
    string preToInfix(string prefix) {
        // Write your code here
        stack<string> st;
        string infix = "";
        int n = prefix.length();
        for (int i=n-1; i>=0; i--) {
            char x = prefix[i];
            if (isalnum(x)) st.push(string(1, x));
            else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                st.push("(" + op1 + x + op2 + ")");
            }
        }
        return st.top();
    }
};