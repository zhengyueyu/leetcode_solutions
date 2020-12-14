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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(k <= 0) return nullptr;
        ListNode* p1 = head;
        ListNode* p2 = head;
        while(k--) {
            if(p1 == nullptr) return nullptr;
            p1 = p1->next;
        }
        while(p1 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};