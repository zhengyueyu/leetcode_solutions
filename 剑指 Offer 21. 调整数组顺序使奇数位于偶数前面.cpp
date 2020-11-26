#include "leetcode.h"
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if(nums.size() == 0) return nums;
        int size = nums.size() - 1;
        int i = 0;
        int j = size - 1;

        while(i <= size / 2 || j >= size / 2) {
            while(i <= size / 2 && !(nums[i] % 2)) i++;
            while(j >= size / 2 && nums[j] % 2) j--;
            if(nums[i] % 2 == 0) {
                swap(nums[i], nums[j]);
            }
        }
        return nums;
    }
};

int main() {
	vector<int> vec{1,2,3,4};
	Solution s;
	s.exchange(vec);
}
