class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> parts;
        while (ss >> word) {
            parts.push_back(word);
        }
        reverse(parts.begin(), parts.end());
        string res;
        for (const string& x : parts) {
            res += x + " ";
        }
        return res.empty() ? "" : res.substr(0, res.size() - 1); // Remove the extra space at the end
    }
};