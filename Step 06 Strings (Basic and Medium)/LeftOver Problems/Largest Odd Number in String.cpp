class Solution {
public:
    string largestOddNumber(string num) {
        int left = 0;
        int right = num.size() - 1;
        while(right >= 0) {
            if(num[right]%2 == 1)
                return num.substr(left, right + 1);
            right--;
        }
        return "";
    }
};