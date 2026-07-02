// https://www.geeksforgeeks.org/problems/find-xor-of-numbers-from-l-to-r/1

class Solution {
  public:
    int findXOR(int l, int r) {
        // code here
        function<int (int)> getXOR_n = [&](int num) -> int {
            int mod = num % 4;
            if (mod == 0) return num;
            if (mod == 1) return 1;
            if (mod == 2) return num + 1;
            if (mod == 3) return 0;
        };
        return getXOR_n(l-1) ^ getXOR_n(r);
    }
};