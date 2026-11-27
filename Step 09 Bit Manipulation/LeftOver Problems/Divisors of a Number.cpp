// https://www.geeksforgeeks.org/problems/all-divisors-of-a-number/1

class Solution {
  public:
    vector<int> getDivisors(int n) {
        // code here
        vector<int> res;
        for (int i = 1; i*i <= n; ++i) {
            if (n%i == 0) res.push_back(i);
        }
        for (int i = res.size()-1; i >= 0; --i) {
            if (res[i] != n/res[i]) res.push_back(n/res[i]);
        }
        return res;
    }
};