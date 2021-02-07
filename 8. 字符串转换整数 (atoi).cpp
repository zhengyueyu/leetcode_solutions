class Solution {
public:
    int myAtoi(string s) {
        int positive = 0;
        long res = 0;
        s.append("#");
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(ch == ' ' && !positive) continue;
            else if(ch == '-' && !positive) positive = -1;
            else if(ch == '+' && !positive) positive = 1;
            else if(isDigit(ch) && !positive) {
                res += res * 10 + ch - '0';
                positive = 1;
            }
            else if(isDigit(ch)) {
                res = res * 10 + (ch - '0');
            }
            else {
                res = positive > 0 ? res : -res;
                return res;
            }
            if(positive == 1 && res > (signed)0x7fffffff) return (int)0x7fffffff;
            if(positive == -1 && -res < (signed)0x80000000) return (int)0x80000000;
        }
        return 0;
    }

    bool isDigit(const char& ch) {
        if(ch >= '0' && ch <= '9')
            return true;
        return false;
    }
};