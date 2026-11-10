//User function Template for C++

class Solution {
public:
    void insertAtBottom(stack<int> &st, int x) {
        if (st.empty()) st.push(x);
        else {
            int temp = st.top();
            st.pop();
            insertAtBottom(st, x);
            st.push(temp);
        }
    }
    void Reverse(stack<int> &st) {
        if (!st.empty()) {
            int x = st.top();
            st.pop();
            Reverse(st);
            insertAtBottom(st, x);
        }
    }
};
