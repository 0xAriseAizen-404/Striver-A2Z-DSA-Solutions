class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        for (int i = 0; i < s.length(); i++) {
            if (map.find(s[i]) == map.end()) {
                for (const auto &pair : map) {
                    if (pair.second == t[i]) {
                        return false;
                    }
                }
                map[s[i]] = t[i];
            } else {
                if (map[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};