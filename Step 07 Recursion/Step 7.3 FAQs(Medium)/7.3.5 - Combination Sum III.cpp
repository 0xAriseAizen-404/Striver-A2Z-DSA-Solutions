class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;

        auto helper = [&](auto&& self, int start, int k, int currSum) -> void {
            if (k == 0) {
                if (currSum == n) ans.push_back(curr);
                return;
            }
            for (int num = start; num <= 9; ++num) {
                if (currSum + num > n) break;
                curr.push_back(num);
                self(self, num + 1, k - 1, currSum + num);
                curr.pop_back();
            }
        };
        helper(helper, 1, k, 0);
        return ans;
    }
};