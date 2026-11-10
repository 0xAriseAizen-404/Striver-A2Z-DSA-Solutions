class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mapp;
        mapp['I'] = 1;
        mapp['V'] = 5;
        mapp['X'] = 10;
        mapp['L'] = 50;
        mapp['C'] = 100;
        mapp['D'] = 500;
        mapp['M'] = 1000;
        
        int integerVal = 0;
        int ind = 0;
        while (ind < s.size()) {
            if (ind < s.size() - 1 && mapp[s[ind]] < mapp[s[ind + 1]]) {
                integerVal += mapp[s[ind + 1]] - mapp[s[ind]];
                ind += 2;
            } else {
                integerVal += mapp[s[ind]];
                ind++;
            }
        }
        return integerVal;
    }
};
