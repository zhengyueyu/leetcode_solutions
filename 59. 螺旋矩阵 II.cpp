class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0) return {};
        vector<vector<int>> res(n, vector<int>(n, 0));
        int left = 0, right = n - 1, top = 0, buttom = n - 1;
        int index = 1;
        while(true) {
            for(int k = left; k <= right; k++) {
                res[top][k] = index;
                index++;
            }
            if(++top > buttom) break;

            for(int k = top; k <= buttom; k++) {
                res[k][right] = index;
                index++;
            }
            if(--right < left) break;

            for(int k = right; k >= left; k--) {
                res[buttom][k] = index;
                index++;
            }
            if(--buttom < top) break;

            for(int k = buttom; k >= top; k--) {
                res[k][left] = index;
                index++;
            }
            if(++left > buttom) break;

        }
        return res;
    }
};