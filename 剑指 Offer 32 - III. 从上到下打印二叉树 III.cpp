/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        deque<TreeNode*> que;
        que.push_back(root);
        bool rever = true;
        while(!que.empty()) {
            int size = que.size();
            vector<int> tmp;
            while(size--) {
                TreeNode* tn = que.front();
                tmp.push_back(tn->val);
                que.pop_front();
                if(tn->left) que.push_back(tn->left);
                if(tn->right) que.push_back(tn->right);
            }
            rever = !rever;
            if (rever) reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
        }
        return res;
    }
}; 