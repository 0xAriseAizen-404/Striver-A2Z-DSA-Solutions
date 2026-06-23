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

// Recursion Solution (DFS)
class Solution {
private:
    void helper(TreeNode *root, int level, vector<vector<int>> &res) {
        if (!root) return;
        if (res.size() == level) res.push_back({root->val});
        else res[level].push_back(root->val);
        helper(root->left, level + 1, res);
        helper(root->right, level + 1, res);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, 0, res);
        return res;
    }
};
// TC: O(n)
// SC: O(h) // O(log n) balanced, O(n) skewed

// Queue Solution (BFS)
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> res;
//         if (!root) return res;
//         queue<TreeNode *> que;
//         que.push(root);
//         while (!que.empty()) {
//             vector<int> v;
//             int sz = que.size();
//             for (int i=0; i<sz; ++i) {
//                 TreeNode *curr = que.front();
//                 v.push_back(curr->val);
//                 if (curr->left) que.push(curr->left);
//                 if (curr->right) que.push(curr->right);
//                 que.pop();
//             }
//             res.push_back(v);
//             v.clear();
//         }
//         return res;
//     }
// };
// TC: O(n)
// SC: O(w)  // O(n) worst case, where w = max width of tree