class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int opens = 0;
        for (const char& ch: s) {
            if (ch == '(') {
                opens += 1;
                if (opens > 1) result += ch;
            } else {
                if (opens > 1) result += ch;
                opens -= 1;
            }
        }
        return result;
    }
};


class Solution {
public:
    string removeOuterParentheses(string paranthesis) {
        stack<char> st;
        string result = "";
        
        for (char x : paranthesis) {
            if (x == '(') {
                if (!st.empty()) {
                    result += x;
                }
                st.push(x);
            } else {
                st.pop();
                if (!st.empty()) {
                    result += x;
                }
            }
        }
        
        return result;
    }
};



// class Solution {
// public:
//     string removeOuterParentheses(string paranthesis) {
//         stack<int> st;
//         string result = "";
//         for (char x: paranthesis) {
//             if (x == '(') st.push(x);
//             else {
//                 if (st.size() == 0) result += x;
//                 if (st.size() == 1) {
//                     st.pop();
//                     continue;
//                 }
//                 else {
//                     while (st.size() != 1) {
//                         result += st.top();
//                         st.pop();
//                     }
//                     result += x;
//                 }
//             }
//         }
//         return result;
//     }
// };