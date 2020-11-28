class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int card = nums[0];
        int count = 0;
        for(const int& i : nums) {
            card == i ? count++ : count--;
            if(!count) {
                card = i;
                count = 1;
            }
        }
        return card;
    }
};