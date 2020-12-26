/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return nullptr;
        Node* head = nullptr;
        Node* tail = nullptr;
        helper(root, head, tail);
        tail->right = head;
        head->left = tail;
        return head;
    }

    void helper(Node* root, Node*& head, Node*& tail) {
        if(root == nullptr) return;
        helper(root->left, head, tail);

        //如果是头节点就更新头节点，如果不是的话就更新tail，这里是双指针的原理（循环中的root和tail构成双指针）
        if(!head) {
            head = root;
        }
        else {
            tail->right = root;
            root->left = tail;
        }
        tail = root;
        //
        
        helper(root->right, head, tail);
    }
};