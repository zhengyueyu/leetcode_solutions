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
    TreeNode* bstToGst(TreeNode* root) {
        helper(root);
        return root;
    }

    void helper(TreeNode* root) {
        if(root == nullptr)
            return;

        //反过来的后序遍历，相当于降序打印搜索二叉树
        bstToGst(root->right);
        sum += root->val;
        root->val = sum;
        bstToGst(root->left);
    }
private:
    int sum = 0;
};