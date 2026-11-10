class Solution {
public:
    int countGoodNumbers(long long n) {
        const int MOD = 1e9 + 7;
        long long evenIndices = (n + 1) / 2;
        long long oddIndices = n / 2;
        long long result1 = myPow(5, evenIndices, MOD);
        long long result2 = myPow(4, oddIndices, MOD);
        return (int)((result1 * result2) % MOD);
    }

private:
    long long myPow(long long x, long long n, int MOD) {
        if (n == 0 || x == 1) return 1;
        if (x == 0) return 0;
        x = x % MOD;  // Handle cases where x is greater than MOD
        long long halfPow = myPow((x * x) % MOD, n / 2, MOD);
        return (n % 2 == 0) ? halfPow : (x * halfPow) % MOD;
    }
};


class Solution {
    static const long long MOD = 1e9 + 7;
private:
    long long modpow(long long x, long long n) {
        long long res = 1;
        x %= MOD;
        while (n > 0) {
            if (n & 1) res = (res * x) % MOD;   // multiply under mod
            x = (x * x) % MOD;                  // square under mod
            n >>= 1;
        }
        return res;
    }
public:
    int countGoodNumbers(long long n) {
        // Rule of Product (Multiplication Principle) Permutations and Combinations.
        // Even digits can only be -> 0, 2, 4, 6, 8 -> 5^(even_positions) => (n+1)/2
        // Prime digits can only be -> 2, 3, 5, 7 -> 4^(odd_positions) => n/2
        return (1LL * (modpow(5, (n + 1) / 2) * modpow(4, n / 2)) % MOD);
    }
};
