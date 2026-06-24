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
    int getHeight(TreeNode *node, int &maxD) {
        if (!node) return 0;
        int leftH = getHeight(node->left, maxD);
        int rightH = getHeight(node->right, maxD);
        maxD = max(maxD, leftH + rightH);
        return max(leftH, rightH) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxD = 0;
        getHeight(root, maxD);
        return maxD;
    }
};
// TC: O(n)
// SC: O(h)  // O(log n) balanced, O(n) skewed