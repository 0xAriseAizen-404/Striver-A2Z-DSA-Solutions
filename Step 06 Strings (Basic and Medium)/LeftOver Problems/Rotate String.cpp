class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        string xxx = goal + goal;
        return xxx.find(s) != string::npos;
        // if(s.size() != goal.size())
        //     return false;
        // while(s != goal) {
        //     s = s.substr(1) + s[0];
        // }
        // return s==goal;
    }
};