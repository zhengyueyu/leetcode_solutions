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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        helper(root, res, path, sum, 0);
        return res;
    }

    void helper(TreeNode* root, vector<vector<int>>& res, vector<int>& path, const int& sum, int totalsum) {
        if(root == nullptr) return;
        totalsum += root->val;
        path.push_back(root->val);
        if(totalsum == sum && root->left == nullptr && root->right == nullptr) res.push_back(path);
        helper(root->left, res, path, sum, totalsum);
        helper(root->right, res, path, sum, totalsum);
        totalsum -= root->val;
        path.pop_back();
    }
};