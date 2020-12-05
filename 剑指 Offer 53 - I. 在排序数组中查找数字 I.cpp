class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int count = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            int cur = mid;
            if(nums[mid] < target) l = mid + 1;
            else if(nums[mid] == target) {
                while(cur >= l && nums[cur] == target) {count++; cur--;}
                cur = mid + 1;
                while(cur <= r && nums[cur] == target) {count++; cur++;}
                return count;
            }
            else if(nums[mid] > target) {
                r = mid - 1;
            } 
        }
        return count;
    }
};