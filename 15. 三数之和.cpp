class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3) return res;

        sort(nums.begin(), nums.end(), less<int>());
        
        for(int i = 0; i < nums.size(); i++) {
            if(i != 0 && nums[i] == nums[i - 1])
                continue;
            int target = nums[i];

            //避免重复
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                int sum = nums[left] + nums[right];
                if(sum < -target) {
                    left++;
                }
                else if(sum > -target) {
                    right--;
                }
                else {
                    res.push_back({target, nums[left], nums[right]});
                    left++; right--;
                    while(left < right && nums[left] == nums[left - 1])
                        left++;
                    while(left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }
        return res;
    }
};