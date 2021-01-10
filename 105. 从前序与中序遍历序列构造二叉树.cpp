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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildHelper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* buildHelper(vector<int>& preorder, vector<int>& inorder, int prestart, int preend, int instart, int inend) {
        if(prestart > preend) 
            return nullptr;
        TreeNode* head = new TreeNode(preorder[prestart]);
        int mid = 0;
        for(int k = instart; k <= inend; k++) {
            if(inorder[k] == preorder[prestart]) {
                mid = k;
                break;
            }
        }
        int leftsize = mid - instart;
        head->left = buildHelper(preorder, inorder, prestart + 1, prestart + leftsize, instart, mid - 1);
        head->right = buildHelper(preorder, inorder, prestart + leftsize + 1, preend, mid + 1, inend);
        return head;
    }
};