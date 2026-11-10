#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    int longestSubarrayWithSum(vector<int>& arr, long long k) {
        unordered_map<long long, int> firstIndex;
        firstIndex[0] = -1;

        long long prefixSum = 0;
        int longest = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];

            auto it = firstIndex.find(prefixSum - k);
            if (it != firstIndex.end()) {
                longest = max(longest, i - it->second);
            }

            // Keep the earliest index for the longest possible subarray.
            firstIndex.emplace(prefixSum, i);
        }

        return longest;
    }

public:
    int longestZeroSumSubarray(vector<int>& arr) {
        return longestSubarrayWithSum(arr, 0);
    }
};