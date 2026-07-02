// https://www.geeksforgeeks.org/problems/odd-or-even3618/1

class Solution {
  public:
    bool isEven(int n) {
        // code here
        return !(n&1);
    }
};