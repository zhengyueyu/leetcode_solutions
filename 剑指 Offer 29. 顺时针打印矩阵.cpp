#include "leetcode.h"
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(!matrix.size() || !matrix[0].size())
            return res;
        int left = 0;
        int top = 0;
        int right = matrix[0].size() - 1;
        int buttom = matrix.size() - 1;
        while(1) {
            for(int i = left; i <= right; i++) 
                res.push_back(matrix[top][i]);
            if(++top > buttom) break;
            for(int i = top; i <= buttom; i++)
                res.push_back(matrix[i][right]);
            if(--right < left) break;
            for(int i = right; i >= left; i--)
                res.push_back(matrix[buttom][i]);
            if(--buttom < top) break;
            for(int i = buttom; i >= top; i--)
                res.push_back(matrix[i][left]);
            if(++left > right) break;
        }
        return res;
    }
};