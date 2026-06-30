// https://www.naukri.com/code360/problems/childrensumproperty_790723?leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode<int> *root) {
    // Write your code here.
    if (!root) return;
    if (root && !root->left && !root->right) return;
    int childSum = 0;
    if (root->left) childSum += root->left->data;
    if (root->right) childSum += root->right->data;
    if (childSum >= root->data) {
        root->data = childSum;
    } else { // childSum < root->data
        if (root->left) root->left->data = root->data;
        if (root->right) root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int totalSum = 0;
    if (root->left) totalSum += root->left->data;
    if (root->right) totalSum += root->right->data;
    if (root->left || root->right) root->data = totalSum;
}  

// https://www.geeksforgeeks.org/problems/children-sum-parent/1

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if (!root) return true;
        if (root && !root->left && !root->right) return true;
        int leftVal = (root->left) ? root->left->data : 0;
        int rightVal = (root->right) ? root->right->data : 0;
        if (root->data != (leftVal + rightVal)) return false;
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};