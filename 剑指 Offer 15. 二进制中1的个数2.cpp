#include "leetcode.h"
class Solution {
public:
    int hammingWeight(unsigned int n) {
        unsigned int flag = 1;
        int count = 0;
        while(flag) {
            if(flag & n) count++;
            flag = flag << 1;
        }
        return count;
    }
};
