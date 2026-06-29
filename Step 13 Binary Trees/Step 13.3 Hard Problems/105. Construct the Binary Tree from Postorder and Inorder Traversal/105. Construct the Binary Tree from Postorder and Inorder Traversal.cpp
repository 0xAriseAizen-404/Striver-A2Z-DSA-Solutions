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
    int preOrderIndex;
    unordered_map<int, int> inOrderIndexMap;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preOrderIndex = 0;
        inOrderIndexMap.clear();
        for (int i=0; i<inorder.size(); ++i) inOrderIndexMap[inorder[i]] = i;
        
        function<TreeNode *(int, int)> func = [&](int left, int right) -> TreeNode *{
            if (left > right) return nullptr;
            int rootValue = preorder[preOrderIndex]; preOrderIndex++;
            TreeNode *root = new TreeNode(rootValue);
            root->left = func(left, inOrderIndexMap[rootValue]-1);
            root->right = func(inOrderIndexMap[rootValue]+1, right);
            return root;
        };
        return func(0, inorder.size()-1);
    }
};