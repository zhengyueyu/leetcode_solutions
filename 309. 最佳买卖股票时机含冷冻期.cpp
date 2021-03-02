class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;

        //后面需要用到i - 2，这里申请多一点空间
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        dp[1][1] = -prices[0];
        for(int i = 2; i < dp.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
            dp[i][1] = max(dp[i - 2][0] - prices[i - 1], dp[i - 1][1]);
        }
        return dp[prices.size()][0];
    }
};