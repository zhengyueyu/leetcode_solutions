class Solution {
public:
    int movingCount(int m, int n, int k) {
        if(!m || !n || k < 0) return 0;
        if(!k) return 1;
        vector<vector<bool>> grid(n, vector<bool>(m, 0));
        int res = 0;
        dfs(grid, k, 0, 0, res);
        return res;
    }
    void dfs(vector<vector<bool>>& grid, int& k, int i, int j, int& res) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || getdigsum(i, j) > k || grid[i][j] != 0) return;
        res++;
        grid[i][j] = 1;
        dfs(grid, k, i + 1, j, res);
        dfs(grid, k, i - 1, j, res);
        dfs(grid, k, i, j + 1, res);
        dfs(grid, k, i, j - 1, res);
    }
private:
    int getdigsum(int a, int b) {
        int sum = 0;
        while(a) {
            sum += a % 10;
            a /= 10;
        }
        while(b) {
            sum += b % 10;
            b /= 10;
        }
        return sum;
    }
};