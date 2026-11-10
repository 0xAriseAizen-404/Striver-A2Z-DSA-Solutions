#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leadersInArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> leaders;

        // Check every element as a possible leader.
        for (int index = 0; index < n; index++) {
            bool isLeader = true;

            /*
             * A greater value on the right
             * removes the current leader candidate.
             */
            for (int right = index + 1; right < n; right++) {
                if (nums[right] > nums[index]) {
                    isLeader = false;
                    break;
                }
            }

            // Add the value only if no greater value was found.
            if (isLeader) {
                leaders.push_back(nums[index]);
            }
        }

        return leaders;
    }
};

int main() {
    vector<int> nums = {10, 22, 12, 3, 0, 6};

    Solution solution;
    vector<int> leaders = solution.leadersInArray(nums);

    for (int value : leaders) {
        cout << value << " ";
    }

    return 0;
}