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

// Recursive Approach
class Solution {
private:
    void preOrder(TreeNode *root, vector<int> &res) {
        if (!root) return;
        res.push_back(root->val);
        preOrder(root->left, res);
        preOrder(root->right, res);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preOrder(root, res);
        return res;
    }
};
// TC: O(n)
// SC: O(h)  // O(log n) balanced, O(n) skewed

// Iterative Approach
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> res;
//         if (!root) return res;
//         stack<TreeNode *> st;
//         st.push(root);
//         while (!st.empty()) {
//             TreeNode *curr = st.top();
//             res.push_back(curr->val);
//             st.pop();
//             if (curr->right) st.push(curr->right);
//             if (curr->left) st.push(curr->left);
//         }
//         return res;
//     }
// };
// Iterative
// TC: O(n)
// SC: O(h)  // O(log n) balanced, O(n) skewed