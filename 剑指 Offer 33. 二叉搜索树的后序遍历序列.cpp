class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size() == 0 || postorder.size() == 1) return true;
        bool flag = true;
        helper(postorder, 0, postorder.size() - 1, flag);
        return flag;
    }

    void helper(vector<int>& postorder, int start, int root, bool& flag) {
        if(!flag || root < 0 || start >= root) return;
        int i = start;

        //这里对postorder的切割应该从小往大切割
        //如果从大往小切割，则到了子树无法比较其右节点和其父节点
        /* while(left >= 0 && postorder[left] >= postorder[root]) left--;
        for(right = left + 1; right < root - 1; right++) {
            if(postorder[right] < postorder[root]) {
                flag = false;
                return;
            } 
        } */

        while(i < root && postorder[i] < postorder[root]) i++;
        for(int k = i; k < root; k++) {
            if(postorder[k] < postorder[root]) {
                flag = false;
                return;
            }
        }
        helper(postorder, start, i - 1, flag);
        helper(postorder, i, root - 1, flag);        
    }
};