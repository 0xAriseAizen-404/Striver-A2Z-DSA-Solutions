class Solution {
public:
    int minBitFlips(int start, int goal) {

        // return __builtin_popcount(start ^ goal);

        int required = start ^ goal;
        int cnt = 0;
        while (required) {
            required = required & (required - 1);
            cnt += 1;
        }
        return cnt;
        
        // int notEqualBits_cnt = 0;
        // for (int i=0; i<32; ++i) {
        //     if ((start&(1 << i)) != (goal&(1 << i)))
        //         notEqualBits_cnt += 1;
        // }
        // return notEqualBits_cnt;
    }
};