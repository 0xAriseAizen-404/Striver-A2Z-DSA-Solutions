#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarraysWithXor(vector<int>& nums, int k) {
        unordered_map<int, long long> prefixCount;
        prefixCount[0] = 1;

        int prefixXor = 0;
        long long count = 0;

        for (int value : nums) {
            prefixXor ^= value;
            int neededXor = prefixXor ^ k;

            if (prefixCount.find(neededXor) != prefixCount.end()) {
                count += prefixCount[neededXor];
            }

            prefixCount[prefixXor]++;
        }

        return count;
    }
};