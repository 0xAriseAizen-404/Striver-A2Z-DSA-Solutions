class Solution {
public:
    bool solve(int idx, int sum, vector<int>& nums, int k) {
        if (sum == k) return true;

        if (idx == nums.size()) return false;

        bool include = solve(idx + 1, sum + nums[idx], nums, k);
        bool exclude = solve(idx + 1, sum, nums, k);

        return include || exclude;
    }

    bool checkSubsequenceSum(int n, vector<int>& nums, int k) {
        return solve(0, 0, nums, k);
    }
};

class Solution {
public:
    int dp[101][10001];

    bool solve(int idx, int sum, vector<int>& nums, int k) {
        if (sum == k) return true;

        if (idx == nums.size() || sum > k) return false;

        if (dp[idx][sum] != -1) return dp[idx][sum];

        bool include = solve(idx + 1, sum + nums[idx], nums, k);
        bool exclude = solve(idx + 1, sum, nums, k);

        return dp[idx][sum] = include || exclude;
    }

    bool checkSubsequenceSum(int n, vector<int>& nums, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, nums, k);
    }
};