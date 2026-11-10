#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersectionResult;

        for (int value : nums1) {
            bool foundInSecond = false;

            // Search for the current value in nums2.
            for (int candidate : nums2) {
                if (candidate == value) {
                    foundInSecond = true;
                    break;
                }
            }

            if (!foundInSecond) {
                continue;
            }

            bool alreadyAdded = false;

            /*
             * Check whether this common value
             * is already present in the result.
             */
            for (int storedValue : intersectionResult) {
                if (storedValue == value) {
                    alreadyAdded = true;
                    break;
                }
            }

            // Add only the first occurrence of a common value.
            if (!alreadyAdded) {
                intersectionResult.push_back(value);
            }
        }

        return intersectionResult;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 2, 3, 4};
    vector<int> nums2 = {2, 2, 4, 5};

    Solution solution;
    vector<int> answer = solution.intersection(nums1, nums2);

    for (int value : answer) {
        cout << value << " ";
    }

    return 0;
}