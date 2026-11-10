// // Optimal Solution
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int sz = nums.size();
        for (int mask=0; mask<(1<<sz); ++mask) {
            vector<int> subset;
            for (int i=0; i<sz; ++i) {
                if (mask & (1 << i)) subset.push_back(nums[i]);
            }
            res.push_back(subset);
        }
        return res;
    }
};
// // TC: O(n * 2^n)
// // SC: O(2^n)

// // Better Solution
// class Solution {
// private:
//     void helper(vector<int> &nums, int n, int ind, vector<int> &curr, vector<vector<int>> &res) {
//         if (ind == n) {
//             res.push_back(curr);
//             return;
//         }
//         // take
//         curr.push_back(nums[ind]);
//         helper(nums, n, ind + 1, curr, res);
//         curr.pop_back();
//         // not take
//         helper(nums, n, ind + 1, curr, res);
//     }
// public:
//     vector<vector<int>> subsets(vector<int> &nums) {
//         int n = nums.size();
//         vector<vector<int>> res;
//         vector<int> curr;
//         helper(nums, n, 0, curr, res);
//         return res;
//     }
// };
// // TC: O(n * 2^n)
// // SC: O(2^n + n)

// // BruteForce Solution
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> res = {{}};
//         // res.push_back({});
//         for (int i=0; i<n; ++i) { // 1 loop, 2 loop, 3 loop
//             int sz = res.size();
//             for (int j=0; j<sz; ++j) {
//                 vector<int> newSubset = res[j];
//                 newSubset.push_back(nums[i]);
//                 res.push_back(newSubset);
//             }
//         }
//         return res;
//         // Start: {}
//         // Add 1: {}, {1}
//         // Add 2: {}, {1}, {2}, {1, 2}
//         // Add 3: {}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}
//     }
// };
// // TC: O(n * 2^n)
// // SC: O(2^n)