class Solution {
private:
    unordered_map<char, string> umap = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };
    void helper(string digits, int ind, string curr, vector<string> &ans) {
        if (curr.size() == digits.size()) {
            ans.push_back(curr);
            return;
        }
        
        for (char c: umap[digits[ind]]) {
            // curr.push_back(c);
            // helper(digits, ind + 1, curr, ans);
            // curr.pop_back();
            helper(digits, ind + 1, curr + c, ans);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        helper(digits, 0, "", ans);
        return ans;
    }
};