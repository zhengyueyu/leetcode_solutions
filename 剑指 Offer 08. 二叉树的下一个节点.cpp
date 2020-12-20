TreeNode* GetNext(TreeNode* node) {
	if(node == nullptr) return nullptr;
	if(node->right) {
		TreeNode* tmp = node->right;
		while(tmp->left != nullptr) {
			tmp = tmp->left;
		}
		return tmp;
	}
	if(node->parent != nullptr) {
		TreeNode* cur = node;
		TreeNode* pre = node->parent;
		while(pre != nullptr && cur == pre->parent) {
			cur = pre;
			pre = pre->parent;
		}
		return pre;
	}
	return nullptr;
}