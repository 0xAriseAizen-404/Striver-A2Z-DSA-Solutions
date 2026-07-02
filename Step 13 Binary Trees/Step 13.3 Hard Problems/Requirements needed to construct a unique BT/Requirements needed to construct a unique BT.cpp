// https://www.geeksforgeeks.org/problems/unique-binary-tree-requirements/1

class Solution {
  public:
    bool isPossible(int a, int b) {
        // code here
        return (a == 2 && b != 2) || (a != 2 && b == 2);
    }
};