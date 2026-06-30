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
// My Own Solution
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int max_len = 0;
        if (!root) return max_len;
        queue<pair<TreeNode *, unsigned long long>> que; que.push({root, 0});
        while (!que.empty()) {
            int sz = que.size();
            int start = -1;
            int end = -1;
            for (int i=0; i<sz; ++i) {
                auto [curr, ind] = que.front(); que.pop();
                if (start == -1) start = ind;
                end = ind;
                if (curr->left) que.push({curr->left, 2 * ind + 1});
                if (curr->right) que.push({curr->right, 2 * ind + 2});
            }
            // if (start == -1 && end == -1) break;
            max_len = max(max_len, end - start + 1);
        }
        return max_len;
    }
};
// TC: O(n)
// SC: O(n/2) // last level // so ~= O(n)