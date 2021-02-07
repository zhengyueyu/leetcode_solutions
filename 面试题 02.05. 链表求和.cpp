/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        ListNode* head = new ListNode(0);
        ListNode* tmp = head;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            tmp->next = new ListNode(sum % 10);
            tmp = tmp->next;
        }
        return head->next;
    }
};