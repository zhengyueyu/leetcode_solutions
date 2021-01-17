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
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        helper(root);
        return root;
    }

    void helper(TreeNode* root) {
        if(root == nullptr) return;
        helper(root->right);
        sum +=root->val;
        root->val = sum;
        helper(root->left);
    }

private:
    int sum = 0;
};