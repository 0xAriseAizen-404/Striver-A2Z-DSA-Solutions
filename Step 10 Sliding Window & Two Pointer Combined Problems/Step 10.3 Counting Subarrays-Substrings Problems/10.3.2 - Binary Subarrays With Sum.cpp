// Optimal Solution
class Solution {
private:
    int helper(vector<int> &nums, int goal) {
        if (goal < 0) return 0;
        int left = 0;
        int sum = 0;
        int cnt = 0;
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            while (sum > goal) sum -= nums[left++];
            cnt += (right - left + 1);
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums, goal) - helper(nums, goal-1);
    }
};
// TC: O(4N)
// SC: O(1)

// Better Solution
// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         unordered_map<int, int> ump;
//         ump[0] = 1;
//         int sum = 0;
//         int cnt = 0;
//         for (int i=0; i<nums.size(); ++i) {
//             sum += nums[i];
//             if (ump.count((sum - goal)))
//                 cnt += ump[(sum - goal)];
//             ump[sum] += 1;
//         }
//         return cnt;
//     }
// };
// TC: O(N)
// SC: O(N)

// BruteForce Solution: TLE
// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int cnt = 0;
//         for (int i=0; i<nums.size(); ++i) {
//             int sum = nums[i];
//             cnt += (sum == goal);
//             for (int j=i+1; j<nums.size(); ++j) {
//                 sum += nums[j];
//                 cnt += (sum == goal);
//             }
//         }
//         return cnt;
//     }
// };
// TC: O(N^2)
// SC: O(1)


class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return myHelper(nums, goal) - myHelper(nums, goal - 1);
    }
    int myHelper(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int left = 0;
        int right = 0;
        int summ = 0;
        int count = 0;
        while (right < nums.size()) {
            summ += nums[right];
            while (summ > goal) summ -= nums[left++];
            count += (right - left + 1);
            right++;
        }
        return count;
    }
};