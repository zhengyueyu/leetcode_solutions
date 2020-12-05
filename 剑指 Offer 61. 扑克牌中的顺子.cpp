class Solution {
public:
    bool isStraight(vector<int>& nums) {
        if(nums.size() > 5) return false;
        int zero = 0;
        sort(nums.begin(), nums.end());
        int j = 0;
        for(; j < nums.size(); j++) {
            if(nums[j] == 0) zero++;
            else break;
        }
        for(int i = j + 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) return false;
            if(nums[i - 1] + 1 == nums[i]) continue;
            int dist = nums[i] - nums[i - 1];
            zero -= dist - 1;
            if(zero < 0) return false;
        }
        return true;
    }
};