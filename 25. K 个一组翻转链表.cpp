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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        ListNode* tmp = head;

        //1、base case:少于k个的数不用翻转
        //2、找到k个一组的下一个节点
        for(int i = 0; i < k; i++) {
            if(tmp == nullptr) 
                return head;
            tmp = tmp->next;
        }

        //获得一组的新的头，即旧的尾
        //这个头等下一次递归返回可以接到左边一组的头部（没有翻转的时候的左边）
        ListNode* newHead = reverse(head, tmp);

        head->next = reverseKGroup(tmp, k);
        return newHead;
    }

    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* nxt = head;
        while(cur != tail) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};