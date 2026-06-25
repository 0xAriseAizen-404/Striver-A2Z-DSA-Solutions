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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightViewNodes;
        if (!root) return rightViewNodes;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            int sz = que.size();
            int isFoundAtThisLevel = false;
            for (int i=0; i<sz; ++i) {
                TreeNode *curr = que.front(); que.pop();
                if (!isFoundAtThisLevel) {
                    rightViewNodes.push_back(curr->val);
                    isFoundAtThisLevel = true;
                }
                if (curr->right) que.push(curr->right);
                if (curr->left) que.push(curr->left);
            }
        }
        return rightViewNodes;
    }
};