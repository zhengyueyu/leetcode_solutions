class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        int i = binsearch(nums, target);
        int j = binsearch(nums, target - 1);
        vector<int> res;
        if(j >= 0 && j < nums.size() && nums[j] == target) return {j, i - 1};
        else return {-1, -1};
    }

    int binsearch(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j) {
            int mid = i + (j - i) / 2;
            if(nums[mid] <= target) i = mid + 1;
            else j = mid - 1;
        }
        return i;
    }

};