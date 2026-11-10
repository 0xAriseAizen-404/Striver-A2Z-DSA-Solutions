class Solution {
private:
    void helper(vector<int> &candidates, int ind, int target, vector<int> &curr_combination, vector<vector<int>> &all_combinations) {
        if (target == 0) {
            all_combinations.push_back(curr_combination);
            return;
        }
        if (ind == candidates.size() || target < 0) return;

        if (candidates[ind] <= target) {
            // Pick Ind
            curr_combination.push_back(candidates[ind]);
            helper(candidates, ind, target - candidates[ind], curr_combination, all_combinations);
            curr_combination.pop_back();
        }

        // Skip Ind
        helper(candidates, ind + 1, target, curr_combination, all_combinations);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> all_combinations;
        vector<int> curr_combination;
        helper(candidates, 0, target, curr_combination, all_combinations);
        return all_combinations;
    }
};



// class Solution {
//     vector<vector<int>> all_combinations;
// private:
//     void helper(vector<int> &candidates, int ind, int target, vector<int> curr_combination) {
//         if (target == 0) {
//             all_combinations.push_back(curr_combination);
//             return;
//         }
//         if (ind == candidates.size() || target < 0) return;

//         // Skip Ind
//         helper(candidates, ind + 1, target, curr_combination);

//         // Pick Ind
//         curr_combination.push_back(candidates[ind]);
//         helper(candidates, ind, target - candidates[ind], curr_combination);
//     }

// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<int> curr_combination;
//         helper(candidates, 0, target, curr_combination);
//         return all_combinations;
//     }
// };