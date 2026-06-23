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
    void postOrder(TreeNode *root, vector<int> &res) {
        if (!root) return;
        postOrder(root->left, res);
        postOrder(root->right, res);
        res.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postOrder(root, res);
        return res;
    }
};
// TC: O(n)
// SC: O(h)  // O(log n) balanced, O(n) skewed

// Iterative Approach
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> res;
//         if (!root) return res;
//         stack<TreeNode *> st;
//         st.push(root);
//         while (!st.empty()) {
//             TreeNode *curr = st.top(); st.pop();
//             res.push_back(curr->val);
//             if (curr->left) st.push(curr->left);
//             if (curr->right) st.push(curr->right);
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };
// TC: O(n)
// SC: O(h)  // O(log n) balanced, O(n) skewed