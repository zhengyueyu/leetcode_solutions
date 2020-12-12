class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int col = matrix[0].size();
        int row = matrix.size();
        int i = 0;
        int j = col - 1;
        while(i < row && j >= 0) {
            // 利用从左到右递增、从上到下递增的规则
            // 从右到左剔除列，从上到下剔除行
            if(matrix[i][j] == target) return true;
            if(matrix[i][j] > target) j--;
            else if(matrix[i][j] < target) i++;
        }
        return false;
    }
};