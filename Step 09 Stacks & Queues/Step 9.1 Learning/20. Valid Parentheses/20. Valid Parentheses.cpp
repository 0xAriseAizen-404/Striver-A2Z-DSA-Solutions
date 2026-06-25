class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        auto isOpeningOne = [](char x) {
            return x == '(' || x == '[' || x == '{';
        };
        for (char x : s) {
            if (isOpeningOne(x)) {
                st.push(x);
            } else {
                if (st.empty()) return false;
                if (st.top() == '(' && x == ')') st.pop();
                else if (st.top() == '[' && x == ']') st.pop();
                else if (st.top() == '{' && x == '}') st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};
