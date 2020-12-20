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
        if(root == nullptr) return root;
        helper(root);
        tail->right = head;
        head->left = tail;
        return head;
    }

    void helper(Node* root) {
        if(root == nullptr) return;
        if(root->left) helper(root->left);
        if(!tail) {
            head = root;
        }
        else {
            tail->right = root;
            root->left = tail;
        }
        tail = root;
        if(root->right) helper(root->right);
    }

private:
    Node* head = nullptr;
    Node* tail = nullptr;
};