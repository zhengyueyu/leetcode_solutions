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
        if(preorder.size() != inorder.size() || preorder.empty()) return nullptr;
        return buildHelper(0, preorder, inorder, 0, preorder.size() - 1);
    }

    //root是根节点在preorder中的下标，而不是值
    TreeNode* buildHelper(int root, vector<int>& preorder, vector<int>& inorder, int i, int j) {
        if(i > j) return nullptr;
        int index = i;
        TreeNode* tmp = new TreeNode(preorder[root]);
        //利用inorder来找到root在preorder中的位置，index就是用来判断左右子树位置的
        while(index < j && inorder[index] != preorder[root]) index++;
        tmp->left = buildHelper(root + 1, preorder, inorder, i, index - 1);
        tmp->right = buildHelper(root + (index - i) + 1, preorder, inorder, index + 1, j);
        return tmp;
    }
};

//inorder用来判断左右子树的长度，以便在preorder中寻找左右子树