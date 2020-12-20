class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int dp = nums[0];
        int maxans = dp;
        for(int i = 1; i < nums.size(); i++) {
            dp = nums[i] > nums[i] + dp ? nums[i] : nums[i] + dp;
            maxans = dp > maxans ? dp : maxans;
        }
        return maxans;
    }
};