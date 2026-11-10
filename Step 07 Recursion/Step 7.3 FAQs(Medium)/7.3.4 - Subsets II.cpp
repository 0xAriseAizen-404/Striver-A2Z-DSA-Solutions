class Solution {
private:
    void helper(vector<int>& nums, int ind, vector<int>& curr, vector<vector<int>>& ans) {
        ans.push_back(curr);

        for (int k = ind; k < nums.size(); k++) {
            if (k > ind && nums[k] == nums[k - 1]) continue;

            curr.push_back(nums[k]);
            helper(nums, k + 1, curr, ans);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(nums, 0, curr, ans);
        return ans;
    }
};

// Recursive Solution
// class Solution {
// private:
//     void helper(vector<int> &nums, int ind, vector<int> &curr, vector<vector<int>> &ans) {
//         if (ind == nums.size()) {
//             ans.push_back(curr);
//             return;
//         }
//         // Pick Ind
//         curr.push_back(nums[ind]);
//         helper(nums, ind + 1, curr, ans);
//         curr.pop_back();
//         // Skip Ind and Skip Duplicates
//         while (ind+1 < nums.size() && nums[ind] == nums[ind+1]) ind += 1;
//         helper(nums, ind + 1, curr, ans);
//     }
// public:
//     vector<vector<int>> subsetsWithDup(vector<int> &nums) {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> ans;
//         vector<int> curr;
//         helper(nums, 0, curr, ans);
//         return ans;
//     }
// };

// BitMask Solution
// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         set<vector<int>> anss;
//         for (int mask = 0; mask < (1 << n); ++mask) {
//             vector<int> curr;
//             for (int i = 0; i < n; ++i) {
//                 if (mask & (1 << i)) curr.push_back(nums[i]);
//             }
//             anss.insert(curr);
//         }
//         vector<vector<int>> ans(anss.begin(), anss.end());
//         return ans;
//     }
// };