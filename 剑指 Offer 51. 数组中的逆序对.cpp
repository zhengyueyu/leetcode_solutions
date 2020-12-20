class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> tmp(nums.size());
        return mergesort(nums, tmp, 0, nums.size() - 1);
    }

    int mergesort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if(l >= r) return 0;
        int mid = (l + r) / 2;
        int inv_count = mergesort(nums, tmp, l, mid) + mergesort(nums, tmp, mid + 1, r);
        int i = l;
        int j = mid + 1;
        int pos = l;
        while(i <= mid && j <= r) {
            if(nums[i] > nums[j]) {
                tmp[pos++] = nums[j++];
            }
            else {
                tmp[pos++] = nums[i++];
        
 //       L = [8, 12, 16, 22, 100]   R = [9, 26, 55, 64, 91]  M = [8, 9]
 //               |                          |
 //             lPtr                       rPtr
 //     当lptr指向12时，会发现右边相应0 - rptr范围内有一个数比它小,这就是下面inv_count的来源
 //     
                inv_count += j - (mid + 1);                     
            }
        }
        for(int k = i; k < mid + 1; k++) {
            tmp[pos++] = nums[k];
            inv_count += j - (mid + 1);
        }
        for(int k = j; k <= r; k++) {
            tmp[pos++] = nums[k];
        }

        // 将部分排序的tmp复制到nums，避免上层递归重复计算已经计算过的inv_count
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return inv_count;
    }
};