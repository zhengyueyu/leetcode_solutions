class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        if(nums.size() == 0) return {};
        int x = 0;
        for(auto& i : nums) x ^= i;

        //tips: 一个数的相反数的二进制只有 右侧第一个1及其之后的位 和原数相同，这里是找到最右边的1
        int flag = x & (-x);

        int res = 0;
        for(auto& i : nums) 
            if((flag & i) != 0)
                res ^= i;
        return {res, x ^ res};
    }
};