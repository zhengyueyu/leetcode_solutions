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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == nullptr || cloned == nullptr || target == nullptr)
            return nullptr;
        string path;
        dfs(original, target, path);
        for(int i = 0; i < r_path.size(); i++) {
            if(r_path[i] == 'l') cloned = cloned->left;
            else if(r_path[i] == 'r') cloned = cloned->right;
        }
        return cloned;
    }

    void dfs(TreeNode* original, TreeNode* target, string& path) {
        if(original == nullptr || target == nullptr || !r_path.empty())
            return;
        if(original == target) {
            r_path = path;
            return;
        }

        path.append("l");
        dfs(original->left, target, path);
        path.pop_back();
        path.append("r");
        dfs(original->right, target, path);
        path.pop_back();
    }

private:
    string r_path;
};