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

// class Solution {
//     bool isMirror(TreeNode *node1, TreeNode *node2) {
//         if (!node1 && !node2) return true;
//         if (!node1 || !node2) return false;
//         return node1->val == node2->val && 
//                 isMirror(node1->left, node2->right) &&
//                 isMirror(node1->right, node2->left);
//     }
// public:
//     bool isSymmetric(TreeNode* root) {
//         return isMirror(root->left, root->right);
//     }
// };
// TC: O(n)
// SC: O(h)

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *> que;
        if (!root->left && !root->right) return true;
        if (!root->left || !root->right) return false;
        que.push(root->left);
        que.push(root->right);
        while (!que.empty()) {
            TreeNode *node1 = que.front(); que.pop();
            TreeNode *node2 = que.front(); que.pop();
            if (!node1 && !node2) continue;
            if (!node1 || !node2 || node1->val != node2->val) return false;
            que.push(node1->left); que.push(node2->right);
            que.push(node1->right); que.push(node2->left);
        }
        return true;
    }
};
// TC: O(n)
// SC: O(w)  // O(n) worst case, where w is the maximum width of the tree