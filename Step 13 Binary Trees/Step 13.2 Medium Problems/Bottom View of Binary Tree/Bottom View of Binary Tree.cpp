// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        map<int, int> mp;
        queue<pair<Node *, int>> que;
        que.push({root, 0});
        while (!que.empty()) {
            auto &[node, col] = que.front(); que.pop();
            mp[col] = node->data; // overwrite everytime
            if (node->left) que.push({node->left, col - 1});
            if (node->right) que.push({node->right, col + 1});
        }
        vector<int> res;
        for (auto &[col, val]: mp) res.push_back(val);
        return res;
    }
};
// TC: O(nlogn)
// SC: O(n)