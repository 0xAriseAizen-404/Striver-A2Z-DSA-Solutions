#include <string>
#include <climits>

class Solution {
public:
    int myAtoi(string s) {
        int integerVal = 0;
        bool isNegative = false;
        int ind = 0;
        while (ind < s.size() && isspace(s[ind])) {
            ind++;
        }
        if (ind < s.size() && (s[ind] == '+' || s[ind] == '-')) {
            isNegative = (s[ind] == '-');
            ind++;
        }
        while (ind < s.size() && isdigit(s[ind])) {
            int digit = s[ind] - '0';
            // overflow of value
            if (integerVal > (INT_MAX - digit) / 10) {
                return isNegative ? INT_MIN : INT_MAX;
            }
            integerVal = integerVal * 10 + digit;
            ind++;
        }

        return isNegative ? -integerVal : integerVal;
    }
};
