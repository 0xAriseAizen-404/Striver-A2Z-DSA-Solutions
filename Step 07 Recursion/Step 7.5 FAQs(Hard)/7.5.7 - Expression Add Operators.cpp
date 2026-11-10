class Solution {
private:
    void helper(string num, int target, int ind, long calc, long tail, string curr, vector<string> &ans) {
        if (ind == num.size()) {
            if (calc == target) ans.push_back(curr);
            return;
        }
        long number = 0;
        string part = "";
        for (int i = ind; i < num.size(); ++i) {
            if (i > ind && num[ind] == '0') break;
            number = number * 10 + (num[i] - '0');
            part += num[i];
            if (ind == 0) {
                helper(num, target, i + 1, number, number, part, ans);
            } else {
                helper(num, target, i + 1, calc + number, number, curr + "+" + part, ans);
                helper(num, target, i + 1, calc - number, -number, curr + "-" + part, ans);
                helper(num, target, i + 1, calc - tail + tail * number, tail * number, curr + "*" + part, ans);
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        helper(num, target, 0, 0, 0, "", ans);
        return ans;
    }
};