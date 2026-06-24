// Optimal Solution
class Solution {
private:
    int helper(vector<int> &nums, int k) {
        if (k < 0) return 0;
        int left = 0;
        int sum = 0;
        int cnt = 0;
        for (int right = 0; right < nums.size(); ++right) {
            sum += (nums[right]&1);
            while (sum > k) sum -= (nums[left++]&1);
            cnt += (right - left + 1);
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k-1);
    }
};
// TC: O(4N)
// SC: O(1)

// Better Solution
// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         unordered_map<int, int> ump;
//         ump[0] = 1;
//         int sum = 0;
//         int cnt = 0;
//         for (int i=0; i<nums.size(); ++i) {
//             sum += (nums[i]&1);
//             if (ump.count((sum - k)))
//                 cnt += ump[(sum - k)];
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
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int cnt = 0;
//         for (int i=0; i<nums.size(); ++i) {
//             int sum = (nums[i]&1);
//             cnt += (sum == k);
//             for (int j=i+1; j<nums.size(); ++j) {
//                 sum += (nums[j]&1);
//                 cnt += (sum == k);
//             }
//         }
//         return cnt;
//     }
// };
// TC: O(N^2)
// SC: O(1)

class Solution {
private:
    int myHelper(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int summ = 0;
        int count = 0;
        while (right < nums.size()) {
            summ += nums[right]&1;
            while (summ > k) summ -= nums[left++]&1;
            count += right - left + 1;
            right++;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // just like binary subarray - even->(0) and odd->(1)
        return myHelper(nums, k) - myHelper(nums, k - 1);
    }
};