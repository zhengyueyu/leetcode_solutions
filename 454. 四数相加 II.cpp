#include "leetcode.h"
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> hash;
        int res = 0;
        for(const int& a : A)
            for(const int& b : B)
                hash[-(a + b)]++;
        for(const int& c : C)
            for(const int& d : D)
                if(hash.end() != hash.find(c + d))
                    res += hash[c + d];
        return res;
    }
};