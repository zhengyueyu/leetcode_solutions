class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return { -1, -1};
        int l = 0;
        int r = nums.size() - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] >= target) r = mid;
            else if(nums[mid] < target) l = mid + 1;
        }
        if(nums[l] != target) return { -1, -1 };
        int res = l;
        r = nums.size();
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] <= target) l = mid + 1;
            else if(nums[mid] > target) r = mid;
        }
        return {res, l - 1};
    }
};