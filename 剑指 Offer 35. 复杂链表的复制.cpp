/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        Node* temp = head;
        while(temp) {
            Node* n = new Node(temp->val);
            n->next = temp->next;
            temp->next = n;
            temp = temp->next->next;
        }
        Node* pre = head;
        Node* cur = head;
        while(pre) {
            cur = pre->next;
            if(pre->random != NULL)
                cur->random = pre->random->next;
            pre = cur->next;
        }
        pre = head;
        cur = head->next;
        Node* h = head->next;
        while(pre) {
            pre->next = pre->next->next;
            pre = pre->next;
            if(cur->next != NULL) {
                cur->next = cur->next->next;
                cur = cur->next;
            }
        }
        return h;
    }
};