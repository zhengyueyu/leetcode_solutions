class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() - 1;
        if(row == -1) return false;
        int col = matrix[0].size() - 1;
        if(col == -1) return false;

        int top = 0;
        int buttom = row;
        while(top < buttom) {
            int mid = top + (buttom - top + 1) / 2;
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] < target) top = mid;
            else if(matrix[mid][0] > target) buttom = mid - 1; 
        }

        int left = 0;
        int right = col;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(matrix[top][mid] == target) return true;
            else if(matrix[top][mid] > target) right = mid - 1;
            else if(matrix[top][mid] < target) left = mid + 1;
        }

        return false;
    }

};