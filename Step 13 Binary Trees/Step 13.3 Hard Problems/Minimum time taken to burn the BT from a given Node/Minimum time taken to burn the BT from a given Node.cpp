// https://www.geeksforgeeks.org/problems/burning-tree/1

/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  private:
    void getParentsNodes(Node *root, unordered_map<Node *, Node *> &parents_node) {
        queue<Node *> que; que.push(root);
        while (!que.empty()) {
            int sz = que.size();
            for (int i=0; i<sz; ++i) {
                Node *node = que.front(); que.pop();
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
    bool getTargetAdd(Node *node, int target, Node* &targetAdd) {
        if (!node) return false;
        if (node->data == target) {
            targetAdd = node;
            return true;
        }
        if (getTargetAdd(node->left, target, targetAdd) || getTargetAdd(node->right, target, targetAdd))
            return true;
        return false;
    }
    // Node* getTargetAddress(Node* node, int target) {
    //     if (!node) return nullptr;
    //     if (node->data == target) return node;
    //     Node* left = getTargetAddress(node->left, target);
    //     if (left) return left;
    //     return getTargetAddress(node->right, target);
    // }
  public:
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node *, Node *> parents_node;
        getParentsNodes(root, parents_node);
        
        Node *targetAdd = nullptr;
        getTargetAdd(root, target, targetAdd);
        
        unordered_set<Node *> visited;
        queue<Node *> que; que.push(targetAdd);
        visited.insert(targetAdd);
        int minTime = -1;
        while (!que.empty()) {
            int sz = que.size();
            for (int i=0; i<sz; ++i) {
                Node *node = que.front(); que.pop();
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
            minTime += 1;
        }
        parents_node.clear();
        visited.clear();
        return minTime;
    }
};

// This is wrong approach
// You only consider the longest root-to-leaf path.
// But the answer depends on the maximum distance from the target node to any node in the tree.
//          2
//      3       4
//  5       6
//              7
//                  8
//                      9
//                          10
// Now it consider -> 
// 2, 3, 5
// 2, 3, 6, 7, 8, 9, 10
// as there is no target common_path
// return longestPaths[0].size() + targetPath.size() - 2; // this is valid if the longest_path and target_path are on opposide subtrees of the root
// 7 + 3 - 2 = 8, you assune, 5 -> 3, 2, 3, 6, 7, 8, 9, 10 longest burning path
// In Fact real way of burning is, 5 -> 3, 6, 7, 8, 9, 10 longest burning path
                
// class Solution {
//   private:
//     void getLongestPath(Node *node, vector<int> &path, vector<vector<int>> &longestPaths) {
//         if (!node) return;
//         path.push_back(node->data);
//         if (!node->left && !node->right) {
//             if (longestPaths.empty() ||
//                 path.size() > longestPaths[0].size()) {
//                 longestPaths.clear();
//                 longestPaths.push_back(path);
//             }
//             else if (path.size() == longestPaths[0].size()) {
//                 longestPaths.push_back(path);
//             }
//         }
//         getLongestPath(node->left, path, longestPaths);
//         getLongestPath(node->right, path, longestPaths);
//         path.pop_back();
//     }

//     bool getTargetPath(Node *node, int target, vector<int> &targetPath) {
//         if (!node) return false;
//         targetPath.push_back(node->data);
//         if (node->data == target) return true;
//         if (getTargetPath(node->left, target, targetPath) ||
//             getTargetPath(node->right, target, targetPath))
//             return true;
//         targetPath.pop_back();
//         return false;
//     }

//   public:
//     int minTime(Node* root, int target) {
//         vector<int> targetPath;
//         getTargetPath(root, target, targetPath);

//         vector<vector<int>> longestPaths;
//         vector<int> path;
//         getLongestPath(root, path, longestPaths);

//         bool common_path = false;
//         for (auto &p : longestPaths) {
//             int ind = 0;
//             for (int x : p) {
//                 if (ind < targetPath.size() && x == targetPath[ind])
//                     ind++;
//             }
//             if (ind == targetPath.size()) {
//                 common_path = true;
//                 break;
//             }
//         }
//         if (common_path && longestPaths.size() == 1)
//             return longestPaths[0].size() - targetPath.size() + 1;
//         return longestPaths[0].size() + targetPath.size() - 2;
//     }
// };