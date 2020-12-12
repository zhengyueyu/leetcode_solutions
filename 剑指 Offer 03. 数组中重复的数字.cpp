class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i && nums[i] == nums[nums[i]]) return nums[i];
            swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};