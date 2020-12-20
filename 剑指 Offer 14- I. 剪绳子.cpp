class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= n; i++) {
            for(int j = 2; j < i; j++) {
                //max中加上dp[i]是因为避免j循环，在j较小时dp[i]已经取得较大值，后在j较大时dp[i]被改变
                dp[i] = max(dp[i], max(j * (i - j), dp[i - j] * j));
            }
        }
        return dp[n];
    }
};