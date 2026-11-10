class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::unordered_map<char, int> hmap;
        
        for (char x : s) {
            hmap[x] = hmap[x] + 1;
        }

        for (char x : t) {
            if (hmap[x] != 0) {
                hmap[x] = hmap[x] - 1;
            } else {
                return false;
            }
        }

        return true;

    }
};