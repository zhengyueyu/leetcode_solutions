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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* tmp = st.top();
            st.pop();
            if(p->val < tmp->val && q->val < tmp->val) st.push(tmp->left);
            else if(p->val > tmp->val && q->val > tmp->val) st.push(tmp->right);
            else return tmp;
        }
        return nullptr;
    }
};