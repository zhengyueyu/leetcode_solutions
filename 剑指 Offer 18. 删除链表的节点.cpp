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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == nullptr) return head;
        if(head->val == val) return head->next;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while(cur != nullptr){
            if(cur->val == val){
                pre->next = cur->next;
            }
            pre = pre->next;
            if(pre != nullptr){
                cur = pre->next;
            }
            else{
                cur = nullptr;
            }
        }
        return head;
    }
};