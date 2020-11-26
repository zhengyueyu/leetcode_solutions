#include "leetcode.h"
class Solution {
public:
    int hammingWeight(int n) {
        bitset<32> bs(n);
        return bs.count();
        
    }
};

