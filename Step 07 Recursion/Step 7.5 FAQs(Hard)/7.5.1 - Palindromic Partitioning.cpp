class Solution {
private:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void helper(string s, vector<string> &help, vector<vector<string>> &ans, int ind) {
        if (ind == s.length()) {
            ans.push_back(help);
            return;
        }
        for (int x = ind; x < s.length(); ++x) {
            string str = s.substr(ind, x - ind + 1);
            if (isPalindrome(str)) {
                help.push_back(str);
                helper(s, help, ans, x + 1);
                help.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> help;
        helper(s, help, ans, 0);
        return ans;
    }
};