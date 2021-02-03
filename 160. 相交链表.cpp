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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) 
            return nullptr;
        ListNode* n1 = headA;
        ListNode* n2 = headB;
        while(n1 != n2) {
            if(n1->next == nullptr && n2->next == nullptr)
                return nullptr;
            n1 = (n1->next == nullptr ? headB : n1->next);
            n2 = (n2->next == nullptr ? headA : n2->next);
        }
        return n1;
    }
};