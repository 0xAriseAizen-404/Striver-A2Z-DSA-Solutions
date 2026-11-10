class Solution {
private:
    void helper(vector<int> &candidates, int ind, int target, vector<int> &curr_combination, vector<vector<int>> &all_combinations) {
        if (target == 0) {
            all_combinations.push_back(curr_combination);
            return;
        }

        // Start with Unique numbers only
        for (int k=ind; k<candidates.size(); ++k) {
            if (k!=ind && candidates[k-1]==candidates[k]) continue;
            
            if (candidates[k] > target) break;
            curr_combination.push_back(candidates[k]);
            helper(candidates, k + 1, target - candidates[k], curr_combination, all_combinations);
            curr_combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> all_combinations;
        vector<int> curr_combination;
        helper(candidates, 0, target, curr_combination, all_combinations);
        return all_combinations;
    }
};

// class Solution {
// private:
//     void helper(vector<int> &candidates, int ind, int target, vector<int> &curr_combination, vector<vector<int>> &all_combinations) {
//         if (target == 0) {
//             all_combinations.push_back(curr_combination);
//             return;
//         }
//         if (ind == candidates.size() || target < 0) return;

//         // Pick Ind
//         curr_combination.push_back(candidates[ind]);
//         helper(candidates, ind + 1, target - candidates[ind], curr_combination, all_combinations);
//         curr_combination.pop_back();

//         // Skip Ind and also Skip Duplicates
//         while (ind + 1 < candidates.size() && candidates[ind] == candidates[ind + 1]) ind += 1;
//         helper(candidates, ind + 1, target, curr_combination, all_combinations);
//     }
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());
//         vector<vector<int>> all_combinations;
//         vector<int> curr_combination;
//         helper(candidates, 0, target, curr_combination, all_combinations);
//         return all_combinations;
//     }
// };



// Resulted in TLE
// class Solution {
// private:
//     void helper(vector<int> &candidates, int ind, int target, vector<int> &curr_combination, set<vector<int>> &all_combinations) {
//         if (target == 0) {
//             all_combinations.insert(curr_combination);
//             return;
//         }
//         if (ind == candidates.size() || target < 0) return;

//         // Pick Ind
//         curr_combination.push_back(candidates[ind]);
//         helper(candidates, ind + 1, target - candidates[ind], curr_combination, all_combinations);
//         curr_combination.pop_back();

//         // Skip Ind
//         helper(candidates, ind + 1, target, curr_combination, all_combinations);
//     }
// public:
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(), candidates.end());
//         set<vector<int>> all_combinations;
//         vector<int> curr_combination;
//         helper(candidates, 0, target, curr_combination, all_combinations);
//         vector<vector<int>> v(all_combinations.begin(), all_combinations.end());
//         return v;
//     }
// };