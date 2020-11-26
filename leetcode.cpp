#include "leetcode.h"
ListNode* CreateListNode(vector<int>&& vec) {
	ListNode* pre = new ListNode(vec[vec.size() - 1]);
	for (int i = vec.size() - 2; i >= 0; i--) {
		ListNode* node = new ListNode(vec[i], pre);
		pre = node;
	}
	return pre;
}
