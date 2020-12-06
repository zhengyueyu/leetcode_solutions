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
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* tmp = st.top();
            swap(tmp->left, tmp->right);
            st.pop();
            if(tmp->left) st.push(tmp->left);
            if(tmp->right) st.push(tmp->right);
        }
        return root;
    }
};