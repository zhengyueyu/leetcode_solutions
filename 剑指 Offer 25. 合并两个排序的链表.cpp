class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head = merge(l1, l2);
		return head;
	}

	ListNode* merge(ListNode* l1, ListNode* l2) {
		ListNode* minnode = nullptr;
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		if (l1->val <= l2->val) {
			minnode = l1;
			ListNode* tmp = merge(l1->next, l2);
			minnode->next = tmp;
		}
		else if (l1->val > l2->val) {
			minnode = l2;
			ListNode* tmp = merge(l1, l2->next);
			minnode->next = tmp;
		}
		return minnode;
	}
};