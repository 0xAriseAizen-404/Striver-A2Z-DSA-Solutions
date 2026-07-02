// https://www.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1

class Solution {
  public:
    int setBit(int n) {
        // code here
        return n | (n + 1);
    }
};