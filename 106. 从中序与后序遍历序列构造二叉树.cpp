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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildHelper(inorder, postorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* buildHelper(vector<int>& inorder, vector<int>& postorder, int pleft, int pright, int inleft, int inright) {
        if(pleft > pright) return nullptr;
        int rootval = postorder[pright];
        int inroot = 0;

        //1、找到中序遍历的中心
        for(int i = inleft; i <= inright; i++) {
            if(inorder[i] == rootval) {
                inroot = i;
                break;
            }
        }

        TreeNode* head = new TreeNode(rootval);

        //2、找到左子树的大小
        int leftsize = inroot - inleft;

        //3、两边递归
        head->left = buildHelper(inorder, postorder, pleft, pleft + leftsize - 1, inleft, inroot - 1);
        head->right = buildHelper(inorder, postorder, pleft + leftsize, pright - 1, inroot + 1, inright);
        return head;
    }
};