/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 0ms Solution
class Solution {
private:
    vector<tuple<int, int, int>> nodes;
    void dfs(TreeNode *root, int row, int col) {
        if (!root) return;
        nodes.push_back({col, row, root->val});
        dfs(root->left, row + 1, col - 1);
        dfs(root->right, row + 1, col + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        sort(nodes.begin(), nodes.end());
        vector<vector<int>> res;
        int prevCol = INT_MIN;
        for (auto [col, row, val]: nodes) {
            if (prevCol != col) {
                res.push_back({});
                prevCol = col;
            }
            res.back().push_back(val);
        }
        return res;
    }
};

// My Solution
// class Solution {
// private:
//     unordered_map<int, vector<pair<int, int>>> verticalIndexes;
//     void helper(TreeNode *node, int rowInd, int colInd) {
//         if (!node) return;
//         verticalIndexes[colInd].push_back({rowInd, node->val});
//         helper(node->left, rowInd + 1, colInd - 1);
//         helper(node->right, rowInd + 1, colInd + 1);
//     }
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         verticalIndexes.clear();
//         helper(root, 0, 0);
//         int minIndex = 0;
//         int maxIndex = 0;
//         for (auto &[ind, v]: verticalIndexes) {
//             minIndex = min(minIndex, ind);
//             maxIndex = max(maxIndex, ind);
//             sort(v.begin(), v.end());
//         }
//         vector<vector<int>> res;
//         for (int ind = minIndex; ind <= maxIndex; ++ind) {
//             vector<int> temp;
//             for (auto &[row, val]: verticalIndexes[ind]) temp.push_back(val);
//             res.push_back(temp);
//         }
//         return res;
//     }
// };
// TC: 
// DFS: O(n)
// Sorting all vectors: O(n log n)
// Overall: O(n log n)
// SC: O(n)