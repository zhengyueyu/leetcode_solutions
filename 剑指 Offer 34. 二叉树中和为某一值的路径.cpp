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
        dfs(root, sum, 0, res, path);
        return res;
    }

    void dfs(TreeNode* root, int sum, int totalsum, vector<vector<int>>& res, vector<int> path) {
        if(root == nullptr) {
            return;
        }
        totalsum += root->val;
        path.push_back(root->val);

        //需要找到从根节点到叶子节点的路径，所以不能有任一个子节点非空
        if(totalsum == sum && !root->left && !root->right) {
            res.push_back(path);
        }
        dfs(root->left, sum, totalsum, res, path);
        dfs(root->right, sum, totalsum, res, path);
        path.pop_back();
        totalsum -= root->val;
    }


};