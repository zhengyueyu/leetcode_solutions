/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head) return head;
        ListNode* newhead = new ListNode(0, head);
        ListNode* pre = newhead;
        ListNode* cur = head;
        ListNode* tmp = head;
        while(tmp->next) {
            tmp = tmp->next;
            n--;
            if(n <= 0) {
                pre = cur;
                cur = cur->next;
            }
        }

        pre->next = cur->next;
        return newhead->next;
    }
};