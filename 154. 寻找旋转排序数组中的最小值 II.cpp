class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = l;
        while(l < r && nums[l] >= nums[r]) {
            mid = (l + r) / 2;
            if(nums[mid] < nums[l]) r = mid;
            else if(nums[mid] > nums[l]) l = mid + 1;
            else l++;  
        }
        return nums[l];
    }
};