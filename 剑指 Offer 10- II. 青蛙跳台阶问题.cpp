class Solution {
public:
    int numWays(int n) {
        if(n == 0 || n == 1) return 1;
        const int size = 2;
        int step[size] = { 1, 2 };
        for(int i = 3; i <= n; i++) {
            int steps = 0;
            for(int k = 0; k < size; k++) {
                steps = (steps + step[k]) % 1000000007;
            }
            for(int j = 0; j < size - 1; j++) {
                step[j] = step[j + 1];
            }
            step[size - 1] = steps;
        }
        return step[size - 1];
    }
};