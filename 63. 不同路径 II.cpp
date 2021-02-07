class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if(n == 0) return 0;
        int m = obstacleGrid[0].size();
        if(m == 0) return 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        

        int d = 1; //标记第一列是否在某一位上有障碍物
        for(int i = 0; i < n; i++) {
            if(obstacleGrid[i][0] == 1) d = 0;
            dp[i][0] = d;
        }

        d = 1;  //标记第一行是否在某一位上有障碍物
        for(int i = 0; i < m; i++) {
            if(obstacleGrid[0][i] == 1) d = 0;
            dp[0][i] = d;
        }

        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        
        return dp[n - 1][m - 1];
    }
};


