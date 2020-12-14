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
    ListNode *detectCycle(ListNode *head) {

        //判断是否有环
        if(head == nullptr) return nullptr;
        if(head->next == nullptr || head->next == head) 
            return head->next; //只有一个元素时也会有两种情况
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast) {
            slow = slow->next;//让slow先走，如果有环可以先遇上fast
            if(!fast->next) return nullptr;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(fast == nullptr) return nullptr;

        //fast指向头
        fast = head;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};