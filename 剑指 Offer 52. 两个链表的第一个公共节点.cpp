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
        if(headA == nullptr || headB == nullptr) return nullptr;
        ListNode* pa = headA;
        ListNode* pb = headB;
        int da = 0;
        int db = 0;
        while(pa->next != nullptr || pb->next != nullptr) {
            if(pa->next != nullptr) {
                pa = pa->next;
                da++;
            }
            if(pb->next != nullptr) {
                pb = pb->next;
                db++;
            }
        }
        if(pb != pa) return nullptr;
        ListNode* pshort = da > db ? headB : headA;
        ListNode* plong = da > db ? headA : headB;
        int distance = abs(da - db);
        int i = 0;
        while(i != distance) { i++; plong = plong->next;}
        while(plong != pshort) { plong = plong->next; pshort = pshort->next;}
        return pshort;
    }
};