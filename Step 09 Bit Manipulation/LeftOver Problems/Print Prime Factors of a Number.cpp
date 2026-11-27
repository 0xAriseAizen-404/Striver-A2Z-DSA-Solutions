// https://www.geeksforgeeks.org/problems/prime-factor-of-a-number/1

class Solution {
  public:
    vector<int> primeFactors(int n) {
        // code here
        vector<int> res;
        for (int i = 2; i*i <= n; ++i) {
            while (n%i == 0) {
                res.push_back(i);
                n = n/i;
            }
        }
        if (n > 1) res.push_back(n);
        return res;
    }
};
