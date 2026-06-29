// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

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
  private:
    bool isLeaf(Node *node) {
        return node && !node->left && !node->right;
    }
    void addLeftBoundary(Node *root, vector<int> &ans) {
        Node *curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) ans.push_back(curr->data);
            
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    void addLeaves(Node *root, vector<int> &ans) {
        if (!root) return;
        if (isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }
        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }
    void addRightBoundary(Node *root, vector<int> &ans) {
        Node *curr = root->right;
        vector<int> temp;
        while (curr) {
            if (!isLeaf(curr)) temp.push_back(curr->data);
            
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        reverse(temp.begin(), temp.end());
        ans.insert(ans.end(), temp.begin(), temp.end());
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        if (!root) return ans;
        if (!isLeaf(root)) ans.push_back(root->data);
        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);
        return ans;
    }
};