class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int hash[32] = { 0 };
        for(const int& num : nums) {
            unsigned int mask = 1;
            for(int i = 0; i < 32; i++) {
                hash[i] += (num & mask) == 0 ? 0 : 1;
                mask = mask << 1;
            }
        }
        unsigned int res = 0;
        for(int i = 31; i >= 0; i--) {
            res = res << 1;
            res += hash[i] % 3;
        }
        return res;
    }
};