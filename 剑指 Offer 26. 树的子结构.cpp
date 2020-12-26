class Solution {
public:
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (A == nullptr || B == nullptr) return false;
		if (A->val == B->val && subHelper(A, B))
			return true;
		return isSubStructure(A->left, B) || isSubStructure(A->right, B);
	}

	bool subHelper(TreeNode* A, TreeNode* B) {
		if (B == nullptr) return true;
		if (A == nullptr) return false;
		if (A->val != B->val) return false;
		return subHelper(A->left, B->left) && subHelper(A->right, B->right);
	}
};