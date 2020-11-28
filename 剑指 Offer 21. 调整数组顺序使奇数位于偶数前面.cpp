#include "leetcode.h"
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return nums;
        int size = nums.size() - 1;
        int i = 0;
        int j = size;

        while(i <= j) {
            while(i <= j && nums[i] % 2 != 0) i++;
            while(i <= j && nums[j] % 2 == 0) j--;
            if(i <= j)
                swap(nums[i], nums[j]);
            i++; j--;
        }
        return nums;
    }
};