/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "n";
        string left = serialize(root->left);
        string right = serialize(root->right);
        string tmp = to_string(root->val) + "," + move(left) + "," + move(right);
        return tmp;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> elems;
        getVector(data, elems, ',');
        int index = 0;
        return deserializeHelper(elems, index);
    }

private:
    TreeNode* deserializeHelper(vector<string>& elems, int& index) {
        if(index > elems.size() - 1) return nullptr;
        if(elems[index] == "n") return nullptr;
        TreeNode* node = new TreeNode(atoi(elems[index].data()));
        node->left = deserializeHelper(elems, ++index);
        node->right = deserializeHelper(elems, ++index);
        return node;
    }

    void getVector(string& data, vector<string>& res, char flag) {
        istringstream iss(data);
        string tmp;
        while(getline(iss, tmp, flag)) {
            res.push_back(tmp);
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));