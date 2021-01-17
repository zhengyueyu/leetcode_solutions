class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size = matrix.size() * matrix[0].size() - 1;
        if(size == -1) return false;

        int col = matrix[0].size();

        int index = 0;
        while(index <= size) {
            int mid = index + (size - index) / 2;
            if(matrix[mid / col][mid % col] == target)
                return true;
            else if(matrix[mid / col][mid % col] > target)
                size = mid - 1;
            else if(matrix[mid / col][mid % col] < target)
                index = mid + 1;
        }
        return false;
    }

};