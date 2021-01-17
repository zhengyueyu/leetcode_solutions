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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> hash;
        vector<TreeNode*> res;
        helper(root, hash, res);
        return res;
    }

    string helper(TreeNode* root, unordered_map<string, int>& hash, vector<TreeNode*>& res) {
        if(root == nullptr) return "null";
        string left = helper(root->left, hash, res);
        string right = helper(root->right, hash, res);
        string tmp = to_string(root->val) + "," + left + "," + right;
        const auto& it = hash.find(tmp);
        if(hash.end() != it && it->second == 1)
            res.push_back(root);
        hash[tmp]++;
        return tmp;
    }
};