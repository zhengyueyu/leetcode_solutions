/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(0, nums.size() - 1, nums);
    }

    TreeNode* helper(int i, int j, vector<int>& nums) {
        if(i > j) return nullptr;
        int mid = i;
        for(int k = i; k <= j; k++) 
            if(nums[k] > nums[mid])
                mid = k;
        TreeNode* head = new TreeNode(nums[mid]);
        head->left = helper(i, mid - 1, nums);
        head->right = helper(mid + 1, j, nums);
        return head;
    }
};