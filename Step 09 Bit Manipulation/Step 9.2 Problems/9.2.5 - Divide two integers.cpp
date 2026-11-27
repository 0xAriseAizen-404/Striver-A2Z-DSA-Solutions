// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         bool sign = false;
//         if (dividend > 0 && divisor < 0) sign = true;
//         if (dividend < 0 && divisor > 0) sign = true;
//         int numerator = abs(dividend);
//         int denominator = abs(divisor);
//         int cnt = 0;
//         while (numerator >= denominator) {
//             int i = 0;
//             while (denominator * (1 << i) <= numerator) i++;
//             numerator -= (denominator * (1 << i-1));
//             cnt += (1 << (i-1));
//         }
//         return sign ? -cnt : cnt;
//     }
// };

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool sign = false;
        if (dividend > 0 && divisor < 0) sign = true;
        if (dividend < 0 && divisor > 0) sign = true;

        long long numerator = llabs((long long)dividend);
        long long denominator = llabs((long long)divisor);

        long long cnt = 0;

        while (numerator >= denominator) {
            int i = 0;
            while ((denominator << i) <= numerator) i++;
            numerator -= (denominator << (i - 1));
            cnt += (1LL << (i - 1));
        }

        return sign ? -cnt : cnt;
    }
};