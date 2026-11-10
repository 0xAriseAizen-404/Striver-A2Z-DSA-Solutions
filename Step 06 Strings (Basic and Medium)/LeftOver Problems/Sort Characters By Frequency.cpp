class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> char2freq;
        for (auto& c : s) char2freq[c]++;
        auto comp = [&](char a, char b) {
            return char2freq[a] > char2freq[b] || (char2freq[a] == char2freq[b] && a < b);
        };
        vector<char> chars;
        for (auto& it : char2freq) {
            chars.push_back(it.first);
        }
        sort(chars.begin(), chars.end(), comp);
        string result;
        for (char c : chars) {
            result.append(char2freq[c], c);
        }
        return result;
    }
};

        // map<int, vector<char>, greater<int>> freq2chars;
        // for (auto& [c, f] : char2freq) freq2chars[f].push_back(c);
        // string result = "";
        // for (auto& [f, chars] : freq2chars) {
        //     for (auto& c : chars) result.append(f, c);
        // }