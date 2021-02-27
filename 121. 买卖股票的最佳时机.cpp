class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        vector<vector<int>> dp(2, vector<int>(prices.size(), 0));
        dp[1][0] = -prices[0];
        dp[0][0] = 0;
        for(int i = 1; i < dp[0].size(); i++) {
            dp[0][i] = max(dp[1][i - 1] + prices[i], dp[0][i - 1]);
            dp[1][i] = max(-prices[i], dp[1][i - 1]);
        }
        return dp[0][dp[0].size() - 1];
    }
};