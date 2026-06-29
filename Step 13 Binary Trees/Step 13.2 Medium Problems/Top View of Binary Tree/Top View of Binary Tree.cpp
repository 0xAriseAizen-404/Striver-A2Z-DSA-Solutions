// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
//   private:
//     vector<tuple<int, int, int>> nodes;
//     void dfs(Node *root, int row, int col) {
//         if (!root) return;
//         nodes.push_back({col, row, root->data});
//         dfs(root->left, row + 1, col - 1);
//         dfs(root->right, row + 1, col + 1);
//     }
  public:
    vector<int> topView(Node *root) {
        // code here
        // dfs(root, 0, 0);
        // sort(nodes.begin(), nodes.end());
        // vector<int> res;
        // int prevCol = INT_MIN;
        // for (auto &[col, row, val]: nodes) {
        //     if (prevCol != col) {
        //         res.push_back(val);
        //         prevCol = col;
        //     }
        // }
        // return res;
        
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto [node, col] = q.front();
            q.pop();
            if (!mp.count(col)) mp[col] = node->data;
            if (node->left) q.push({node->left, col - 1});
            if (node->right) q.push({node->right, col + 1});
        }
        vector<int> ans;
        for (auto &[col, val] : mp) ans.push_back(val);
        return ans;
    }
};
// TC: O(nlogn)
// SC: O(n)