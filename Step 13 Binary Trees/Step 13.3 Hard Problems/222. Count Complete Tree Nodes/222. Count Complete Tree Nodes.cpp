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

// Lets make this clear
// at a Level, No. of Elememts = 2^level
// level 0, n_l0 = 2^0 = 1
// level 1, n_11 = 2^1 = 2
// level 2, n_l2 = 2^2 = 4
// level 3, n_l3 = 2^3 = 8
// And Now, if the height of the tree is 4 i.e, there are 0, 1, 2, 3 levels are there right
// if height = 4, no. of elements = n_l0 + n_l1 + n_l2 + n_l3 = 2^0 + 2^1 + 2^2 + 2^3 ===== 2^h - 1 = 2^4 - 1 = 15 (1 + 2 + 4 + 8)
// next level elements - 1 == all the levels no. of  elements
// last level contains n/2+1 elements and all the levels contains n/2 elements

// lets say now we want to know how many elements are there in a tree of levels 0, 1, 2, 3 instead of adding all these levels like 2^0 + 2^1 + 2^2 + 2^3, we can define a formula
// Now imagine if we add another level, i.e, level 4 right, it will contains 2^4 = 16 elements and we know the last level contains (all the previous level nodes + 1). so now to get the all the original level elements count.
// last level nodes = all the previous levels nodes  + 1
// 2^4 = all the previous level nodes + 1
// all the level elements = 2^4 - 1, i.e, here 4 is nothing but the assumed level right, or maybe the hieght of the tree, like it contains 0, 1, 2, 3 levels right, so height of the tree is 4.
// thats how, to get count of elements in a complete binary tree = 2^(height / assumed next level) - 1;

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = 1;
        TreeNode *leftN = root;
        while ((leftN = leftN->left)) leftHeight++;
        
        int rightHeight = 1;
        TreeNode *rightN = root;
        while ((rightN = rightN->right)) rightHeight++;
        
        if (leftHeight == rightHeight) return (1 << rightHeight) - 1; // pow(2, leftHeight) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

// class Solution {
// private:
//     void preOrder(TreeNode *node, int &count) {
//         if (!node) return;
//         count++;
//         preOrder(node->left, count);
//         preOrder(node->right, count);
//     }
// public:
//     int countNodes(TreeNode* root) {
//         int count = 0;
//         preOrder(root, count);
//         return count;
//     }
// };