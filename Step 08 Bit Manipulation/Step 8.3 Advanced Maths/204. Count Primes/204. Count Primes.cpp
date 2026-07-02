class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n, true);
        if (n > 0) primes[0] = false;
        if (n > 1) primes[1] = false;
        for (int i = 2; i * i < n; ++i) {
            if (primes[i]) {
                for (int j = i * i; j < n; j += i) primes[j] = false;
            }
        }
        return count(primes.begin(), primes.end(), true);
    }
};

// class Solution {
// public:
//     int countPrimes(int n) {
//         vector<bool> primes(n, true);
//         if (n > 0) primes[0] = false;
//         if (n > 1) primes[1] = false;
//         int cnt = 0;
//         for (int i = 2; i < n; ++i) {
//             if (primes[i]) {
//                 cnt += 1;
//                 for (int j = i * 2; j < n; j += i) primes[j] = false;
//             }
//         }
//         return cnt;
//     }
// };

// class Solution {
// private:
//     bool isPrime(int n) {
//         if (n <= 1) return false;
//         if (n <= 3) return true;
//         if (n % 2 == 0 || n % 3 == 0) return false;
//         for (int i = 5; 1LL * i * i <= n; i += 6) {
//             if (n % i == 0 || n % (i + 2) == 0) return false;
//         }
//         return true;
//     }
// public:
//     int countPrimes(int n) {
//         int cnt = 0;
//         for (int i = 2; i < n; ++i) {
//             if (isPrime(i)) cnt += 1;
//         }
//         return cnt;
//     }
// };