#include <stack>
#include <string>
#include <algorithm>

class Solution {
public:
    int maxDepth(std::string s) {
        std::stack<char> st;
        int maxNested = 0;
        for (char x: s) {
            if (x == '(') {
                st.push(x);
            } else if (x == ')') {
                st.pop();
            }
            maxNested = std::max(maxNested, static_cast<int>(st.size()));
        }
        return maxNested;
    }
};

class Solution {
public:
    int maxDepth(string s) {
        int opens = 0;
        int mx_depth = 0;
        for (char &x: s) {
            if (x == '(') opens++;
            else if (x == ')') opens--;
            mx_depth = max(mx_depth, opens);
        }
        return mx_depth;
    }
};
