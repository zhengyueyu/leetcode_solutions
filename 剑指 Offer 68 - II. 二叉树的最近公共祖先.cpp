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
        if(p == nullptr || q == nullptr || root == nullptr) return nullptr;
        vector<TreeNode*> ppath;
        vector<TreeNode*> qpath;
        bool find = false;
        dfs(root, ppath, p, find);
        find = false;
        dfs(root, qpath, q, find);
        int i = 0;
        TreeNode* res = root;
        while(i < ppath.size() && i < qpath.size()) {
            if(ppath[i] == qpath[i]) res = ppath[i];
            i++;
        }
        return res;
    }

    void dfs(TreeNode* root, vector<TreeNode*>& path, TreeNode* target, bool& find) {
        if(find || root == nullptr) return;
        path.push_back(root);
        if(root == target) {
            find = true;
            return;
        }
        dfs(root->left, path, target, find);
        if(find) return;
        dfs(root->right, path, target, find);
        if(find) return;
        path.pop_back();
    }
};