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
class Solution {
private:
    int getHeight(TreeNode *node) {
        if (!node) return 0;
        int leftH = getHeight(node->left);
        int rightH = getHeight(node->right);
        if (leftH == -1 || rightH == -1 || abs(leftH - rightH) > 1) return -1;
        else return max(leftH, rightH) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) != -1;
    }
};
// TC: O(n)
// SC: O(h)  // O(log n) balanced, O(n) skewed

// class Solution {
// private:
//     int getHeightCheck(TreeNode *node, bool &isValid) {
//         if (!node) return 0;
//         int leftHeight = getHeightCheck(node->left, isValid);
//         int rightHeight = getHeightCheck(node->right, isValid);
//         if (abs(leftHeight - rightHeight) > 1) isValid = false;
//         return max(leftHeight, rightHeight) + 1;
//     }
// public:
//     bool isBalanced(TreeNode* root) {
//         bool isValid = true;
//         getHeightCheck(root, isValid);
//         return isValid;
//     }
// };
// TC: O(n)
// SC: O(h)  // O(log n) balanced, O(n) skewed

// class Solution {
// private:
//     int getHeight(TreeNode *node) {
//         if (!node) return 0;
//         return max(getHeight(node->left), getHeight(node->right)) + 1;
//     }
// public:
//     bool isBalanced(TreeNode* root) {
//         if (!root) return true;
//         if (abs(getHeight(root->left) - getHeight(root->right)) > 1) return false;
//         return isBalanced(root->left) && isBalanced(root->right);
//     }
// };
// TC: O(n²) worst case, O(n log n) balanced
// SC: O(h)  // O(log n) balanced, O(n) skewed