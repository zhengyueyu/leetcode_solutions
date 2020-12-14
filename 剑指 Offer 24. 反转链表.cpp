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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head->next == NULL)
            return head;
        ListNode* low = head;
        ListNode* medium = head->next;
        ListNode* high = head->next->next;
        head->next = NULL;
        while(high != NULL){
            medium->next = low;
            low = medium;
            medium = high;
            high = high->next;
        }
        medium->next = low;
        return medium;
        
    }
};