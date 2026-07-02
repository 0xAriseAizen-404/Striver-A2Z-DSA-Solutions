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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postOrderIndex = postorder.size() - 1;
        unordered_map<int, int> inOrderIndexMap;
        for (int i=0; i<inorder.size(); ++i) inOrderIndexMap[inorder[i]] = i;

        function<TreeNode *(int, int)> build = [&](int left, int right) -> TreeNode *{
            if (left > right) return nullptr;
            int rootValue = postorder[postOrderIndex]; postOrderIndex--;
            TreeNode *root = new TreeNode(rootValue);
            root->right = build(inOrderIndexMap[rootValue] + 1, right);
            root->left = build(left, inOrderIndexMap[rootValue] - 1);
            return root;
        };
        return build(0, postorder.size() - 1);
    }
};