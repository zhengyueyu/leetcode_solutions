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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return symhelper(root->left, root->right);
    }

    bool symhelper(TreeNode* r1, TreeNode* r2) {
        if(r1 == nullptr && r2 == nullptr) return true;
        if(r1 == nullptr || r2 == nullptr) return false;
        return r1->val == r2->val && symhelper(r1->left, r2->right) && symhelper(r1->right, r2->left);
    }
};