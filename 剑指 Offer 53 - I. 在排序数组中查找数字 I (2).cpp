class Solution {
public:
    int search(vector<int>& nums, int target) {
        int tar = target - 1;
        int r = helper(nums, target);
        int l = helper(nums, tar);
        return r - l;
    }

private:
    int helper(vector<int>& nums, int& target) {
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j) {
			//当i == j时可以找到右边界
            int mid = (i + j) / 2;
            if(nums[mid] <= target) i = mid + 1;
            else j = mid - 1;
        }
        return i;
    }
};