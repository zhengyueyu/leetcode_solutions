class Solution {
public:
    vector<int> printNumbers(int n) {
        n--;
        int maxnum = 9;
        while(n--) {
            maxnum = (10 * maxnum + 9);
        }
        vector<int> res(maxnum);
        for(int i = 0; i < maxnum; i++) {
            res[i] = i + 1;
        }
        return res;
    }
};