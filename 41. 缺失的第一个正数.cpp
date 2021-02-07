class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty()) return 1;
        for(int i = 0; i < nums.size(); i++) {
            //while防止swap后未交换位置的元素被交换到已交换区域，造成疏漏
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i + 1) 
                return i + 1;
        }

        return nums.size() + 1;
    }
};