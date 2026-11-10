//User function Template for C++


class Solution {
public:
    void myHelper(vector<string> &res, int num, string str) {
        if (num == 0) {
            res.push_back(str);
            return;
        }
        myHelper(res, num - 1, str + "0");
        if (str.empty() || str.back() != '1') {
            myHelper(res, num - 1, str + "1");
        }
    }

    vector<string> generateBinaryStrings(int num) {
        vector<string> res;
        if (num < 1) return res;
        myHelper(res, num, "");
        return res;
    }
};


// class Solution{
// public:

//     vector<string> myHelper(vector<string> &res, int num, string str) {
//         if (num == 0) res.push_back(str);
//         else {
//             if (str[str.size() - 1] == '1') {
//                 myHelper(res, num - 1, str+"0");
//             } else {
//                 myHelper(res, num - 1, str+"0");
//                 myHelper(res, num - 1, str+"1");
//             }
//         }
//         return res;
//     }
//     vector<string> generateBinaryStrings(int num){
//         //Write your code
//         vector<string> res;
//         if (num < 1) return res;
//         if (num == 1) return {"0", "1"};
//         myHelper(res, num - 1, "0");
//         myHelper(res, num - 1, "1");
//         return res;
//     }
// };