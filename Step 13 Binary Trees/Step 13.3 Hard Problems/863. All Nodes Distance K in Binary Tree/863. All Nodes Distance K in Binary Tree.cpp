/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void getParentsNodes(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parents_node) {
        queue<TreeNode *> que; que.push(root);
        while (!que.empty()) {
            int sz = que.size();
            for (int i=0; i<sz; ++i) {
                TreeNode *node = que.front(); que.pop();
                if (node->left) {
                    parents_node[node->left] = node;
                    que.push(node->left);
                }
                if (node->right) {
                    parents_node[node->right] = node;
                    que.push(node->right);
                }
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *, TreeNode *> parents_node; // node -> parent
        getParentsNodes(root, parents_node);
        
        unordered_set<TreeNode *> visited;
        queue<TreeNode *> que; que.push(target);
        visited.insert(target);
        int distance = -1;
        while (!que.empty()) {
            if (++distance == k) break; // Going upto Kth level from Target node
            int sz = que.size();
            for (int i=0; i<sz; ++i) {
                TreeNode *node = que.front(); que.pop();
                if (node->left && !visited.count(node->left)) {
                    que.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    que.push(node->right);
                    visited.insert(node->right);
                }
                if (parents_node[node] && !visited.count(parents_node[node])) {
                    que.push(parents_node[node]);
                    visited.insert(parents_node[node]);
                }
            }
        }
        vector<int> res;
        while (!que.empty()) {
            res.push_back(que.front()->val); que.pop();
        }
        return res;
    }
};