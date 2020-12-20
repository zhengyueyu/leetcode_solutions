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
	bool isBalanced(TreeNode* root) {
		bool flag = true;
        helper(root, flag);

		return flag;
	}

	int helper(TreeNode* root, bool& flag) {
		if (root == nullptr || flag == false) return 0;
		int l = helper(root->left, flag) + 1;
		if (flag == false) return 0;
		int r = helper(root->right, flag) + 1;
		if (flag == false) return 0;
		if (abs(l - r) > 1) {
			flag = false;
			return 0;
		}
		
		return max(l, r);
	}
};