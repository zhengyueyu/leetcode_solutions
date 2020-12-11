class Solution {
public
	int cuttingRope(int n) {
		vectorint dp(n + 1);
		dp[0] = 0;
		dp[1] = 1;

		for (int i = 2; i  dp.size(); i++) {
			for (int j = 0; j  i; j++) {
				dp[i] = max(max(j  (i - j), j  dp[i - j]), dp[i]);
			}
		}
		return dp[n];
	}
};