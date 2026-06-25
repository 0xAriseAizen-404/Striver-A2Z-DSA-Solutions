// https://www.geeksforgeeks.org/problems/postfix-to-prefix-conversion/1

class Solution {
  public:
    string postToPre(string postfix) {
        // code here
        stack<string> st;
        string prefix = "";
        for (char &x: postfix) {
            if (isalnum(x)) st.push(string(1, x));
            else {
                string op2 = st.top(); st.pop();
                string op1 = st.top(); st.pop();
                st.push(x + op1 + op2);
            }
        }
        return st.top();
    }
};