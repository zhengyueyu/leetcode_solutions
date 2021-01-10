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
    bool isPalindrome(ListNode* head) {
        left = head;
        return traverse(head);
    }

    bool traverse(ListNode* right) {
        if(right == nullptr) {
            return true;
        }
        bool res = traverse(right->next);
        res = res && (left->val == right->val);
        left = left->next;
        return res;
    }

private:
    ListNode* left;
};