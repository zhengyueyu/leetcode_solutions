class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() == 0) return 0;
        int size = prices.size();
        vector<vector<int>> dp(2, vector<int>(size));
        dp[0][0] = -prices[0];
        dp[1][0] = 0;
        for(int i = 1; i < size; i++) {
            dp[0][i] = max(dp[1][i - 1] - prices[i], dp[0][i - 1]);
            dp[1][i] = max(dp[0][i - 1] - fee + prices[i], dp[1][i - 1]);
        }
        return dp[1][size - 1];
    }
};