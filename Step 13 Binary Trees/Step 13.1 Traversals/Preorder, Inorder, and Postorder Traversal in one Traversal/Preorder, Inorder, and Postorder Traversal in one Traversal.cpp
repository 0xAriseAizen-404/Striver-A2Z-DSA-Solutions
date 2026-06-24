#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<int> preOrder, inOrder, postOrder;
public:
    void preInPostOrderTraversal(TreeNode *root) {
        stack<pair<TreeNode *, int>> st;
        st.push({root, 1});
        if (!root) return;
        while (!st.empty()) {
            auto it = st.top(); st.pop();
            // PreOrder, Increment 1 to 2
            // Push left side of the tree
            if (it.second == 1) {
                preOrder.push_back(it.first->val);
                it.second++;
                st.push(it);
                if (it.first->left) st.push({it.first->left, 1});
            }
            // InOrder, Increment 2 to 3
            // Push right side of the tree
            else if (it.second == 2) {
                inOrder.push_back(it.first->val);
                it.second++;
                st.push(it);
                if (it.first->right) st.push({it.first->right, 1});
            }
            // Don't push it back
            else {
                postOrder.push_back(it.first->val);
            }
        }
    }
};