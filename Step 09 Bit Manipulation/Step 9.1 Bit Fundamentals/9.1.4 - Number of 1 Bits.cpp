class Solution {
public:
    int hammingWeight(int n) {

        int cnt = 0;
        while (n) {
            n = n & (n - 1);
            cnt += 1;
        }
        return cnt;
        
        // int cnt = 0;
        // for (int i=0; i<32; ++i) {
        //     cnt += ((n & (1 << i)) != 0);
        // }
        // return cnt;

        // return __builtin_popcount(n);

        // int cnt = 0;
        // while (n) {
        //     cnt += (n&1);
        //     n >>= 1;
        // }
        // return cnt;
    }
};