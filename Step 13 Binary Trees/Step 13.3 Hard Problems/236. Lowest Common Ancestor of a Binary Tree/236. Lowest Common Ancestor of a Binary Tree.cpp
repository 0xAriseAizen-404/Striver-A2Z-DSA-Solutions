/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Optimal Solution
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        if (!root || root == p || root == q) return root;
        TreeNode *didYouFindAnyNodeOnLeft = lowestCommonAncestor(root->left, p, q);
        TreeNode *didYouFindAnyNodeOnRight = lowestCommonAncestor(root->right, p, q);
        if (didYouFindAnyNodeOnLeft && didYouFindAnyNodeOnRight) return root;
        return didYouFindAnyNodeOnLeft ? didYouFindAnyNodeOnLeft : didYouFindAnyNodeOnRight;
    }
};
// TC: O(n)
// SC: O(h) // Balanced O(nlogn) // Skewed O(n)

// BruteForce Solution
// class Solution {
// private:
//     bool getPath(TreeNode *root, TreeNode *num, vector<TreeNode *> &path) {
//         if (!root) return false;
//         path.push_back(root);
//         if (root == num) return true;
//         if (getPath(root->left, num, path) || getPath(root->right, num, path)) return true;
//         path.pop_back();
//         return false;
//     }
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<TreeNode *> path1; getPath(root, p, path1);
//         vector<TreeNode *> path2; getPath(root, q, path2);
//         int i=0, j=0;
//         TreeNode *ans = root;
//         while (i<path1.size() && j<path2.size()) {
//             if (path1[i] == path2[j]) ans = path1[i];
//             i++, j++;
//         }
//         return ans;
//     }
// };
// TC: O(n)_path1 + O(n)_path2 + O(h)_comparing = O(n)
// SC: O(h)_path1 + O(h)_path2 + O(h)_recursionStack = O(h)