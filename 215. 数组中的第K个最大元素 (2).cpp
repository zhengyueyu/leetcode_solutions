class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty()) return -1;
        
        for(int i = nums.size() / 2 - 1; i >= 0; i--) {
            adjust(nums, i, nums.size() - 1);
        }
        k--;
        for(int i = nums.size() - 1; k > 0; k--, i--) {
            swap(nums[i], nums[0]);
            adjust(nums, 0, i - 1);
        }

        return nums[0];
    }


    void adjust(vector<int>& nums, int i, int j) {
        int parent = i;
        int son = 2 * parent + 1;
        while(son <= j) {
            if(son + 1 <= j && nums[son] < nums[son + 1])
                son++;
            if(nums[parent] > nums[son]) {
                return;
            }
            else {
                swap(nums[parent], nums[son]);
                parent = son;
                son = 2 * parent + 1;
            }
        }
    }

};