// BruteForce Solution
// class Solution {
// public:
//     double myPow(double x, int n) {
//         return pow(x, n);
//     }
// };
// TC: O(log n)
// SC: O(1)

// Optimized Solution
// class Solution {
//     double powPos(double x, long long p) {  // p >= 0
//         if (p == 0) return 1.0;
//         double half = powPos(x * x, p / 2);
//         return (p & 1) ? x * half : half;
//     }
// public:
//     double myPow(double x, int n) {
//         long long p = n;
//         if (p < 0) return 1.0 / powPos(x, -p);
//         return powPos(x, p);
//     }
// };
// TC: O(log n)
// SC: O(log n)

// Optimized Solution 2.0
class Solution {
public:
    double myPow(double x, int n) {
        long long p = n;
        if (p < 0) x = 1.0 / x, p = -p;
        double res = 1.0;
        while (p) {
            if (p & 1) res *= x; // if it is even x * half, here x comes first
            x *= x; // Same step x*x for even or odd, this is HALF
            p >>= 1; // P/2
        }
        return res;
    }
};
// TC: O(log n)
// SC: O(1)