#include "leetcode.h"
class Solution {
public:
    int strToInt(string str) {
        const char* chars = str.data();
        int i = 0;
        long res = 0;
        while(chars[i] == ' ') i++;
        if(i == str.size()) return 0;
        bool negative = false;
        if(chars[i] == '-') {
            negative = true;
            i++;
        }
        else if(chars[i] == '+') i++;
        while(chars[i] != '\0') {
            if(!isdigit(chars[i])) break;
            res = res * 10 + (chars[i] - '0');
            i++;
            if(negative && -res < (signed)0x80000000) return (signed)0x80000000;
            else if(!negative && res > 0x7fffffff) return 0x7fffffff;
        }
        return negative ? -res : res;
    }

private:
    bool isdigit(char c) {
        return (c < '0' || c > '9') ? false : true;
    }
};
