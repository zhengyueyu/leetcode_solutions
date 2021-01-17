class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int i = 0;
        int j = nums.size() - 1;
        
        while(i < j) {
            int mid = i + (j - i) / 2;
            if(nums[mid + 1] != nums[mid] && nums[mid - 1] != nums[mid])
                return nums[mid];
            else if(nums[mid] == nums[mid - 1]) {
                if(mid % 2 == 0) j = mid - 2;
                else i = mid + 1;
            }
            else if(nums[mid] == nums[mid + 1]) {
                if(mid % 2 == 0) i = mid + 2;
                else j = mid - 1;
            }
        }
        return nums[i];
    }
};