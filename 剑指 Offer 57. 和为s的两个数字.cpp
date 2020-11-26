class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r) {
            if(target == nums[l] + nums[r]) return { nums[l], nums[r] };
            else if(target > nums[l] + nums[r]) l++;
            else r--;
        }
        return {};
    }
};
