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
        if(p == q) return q;
        helper(root, p, q);
        return res == nullptr ? root : res;
    }

    bool helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return false;
        if(res != nullptr) return false;
        bool l = helper(root->left, p, q);
        
        bool r = helper(root->right, p, q);

        if((p == root || q == root) && (l || r)) {
            res = root;
            return true;
        }
        else if((l && r) && res == nullptr) {
            res = root;
            return true;
        }
        else if(p == root || q == root) {
            return true;
        }
        else if(l || r) return true;
        return false;
    }

private: 
    TreeNode* res = nullptr;
};