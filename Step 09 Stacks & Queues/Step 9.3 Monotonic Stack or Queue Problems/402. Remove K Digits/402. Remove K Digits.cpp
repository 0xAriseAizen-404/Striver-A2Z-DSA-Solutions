class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for (char &x: num) {
            while (!ans.empty() && ans.back() > x && k) {
                ans.pop_back();
                k -= 1;
            }
            if (!ans.empty() || x!='0') ans.push_back(x);
        }
        while (!ans.empty() && k--) ans.pop_back();
        return ans.empty() ? "0" : ans;
    }
};

// class Solution {
// public:
//     string removeKdigits(string num, int k) {
//         stack<char> mis;
//         for (char &x: num) {
//             while (!mis.empty() && mis.top() > x && k) {
//                 mis.pop();
//                 k -= 1;
//             }
//             if (!mis.empty() || x!='0') mis.push(x);
//             // if it is Empty and the first char is '0' -> False || False -> Don't push
//         }
//         while (!mis.empty() && k--) mis.pop();

//         string ans = "";
//         while (!mis.empty()) {
//             ans += mis.top();
//             mis.pop();
//         }
//         reverse(ans.begin(), ans.end());
//         return ans.empty() ? "0" : ans;
//     }
// };