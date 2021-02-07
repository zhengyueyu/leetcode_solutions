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
    int widthOfBinaryTree(TreeNode* root) {
        int res = 0;
        if(root == nullptr) return res;
        vector<int> left;
        dfs(left, root, 1, 1L, res);
        return res;
    }

    void dfs(vector<int>& left, TreeNode* root, int level, unsigned long long index, int& res) {
        if(root == nullptr) return;

        if(left.size() < level) {
            left.push_back(index);
        }
        dfs(left, root->left, level + 1, 2 * index + 1, res);
        
        dfs(left, root->right, level + 1, 2 * index + 2, res);

        res = max(res, (int)(index - left[level - 1] + 1));
    }
};