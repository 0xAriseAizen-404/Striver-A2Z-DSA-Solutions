// https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

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
    bool getPath(Node *node, int num, vector<int> &path) {
        if (!node) return false;
        path.push_back(num);
        if (node->data == num) return true;
        if (getPath(node->left, num, path) || getPath(node->right, num, path)) return true;
        path.pop_back();
        return false;
    }
    void getPaths(Node *node, vector<int> &leafPath, vector<vector<int>> &paths) {
        if (!node) return;
        leafPath.push_back(node->data);
        if (node && !node->left && !node->right) paths.push_back(leafPath);
        getPaths(node->left, leafPath, paths);
        getPaths(node->right, leafPath, paths);
        leafPath.pop_back();
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> paths;
        vector<int> leafPath;
        getPaths(root, leafPath, paths);
        return paths;
    }
};