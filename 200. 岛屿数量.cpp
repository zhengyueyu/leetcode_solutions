class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) 
            return 0;
        
        vector<vector<bool>> visit(grid.size(), vector(grid[0].size(), false));
        for(int i = 0; i < grid.size(); i++) 
            for(int j = 0; j < grid[0].size(); j++) {
                if(visit[i][j] == false && grid[i][j] == '1') {
                    dfs(grid, visit, i, j);
                    res++;
                }
            }
        return res;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visit, int i, int j) {
        if(i < 0 || i > grid.size() - 1 || j < 0 || j > grid[0].size() - 1 || visit[i][j] == true || grid[i][j] == '0')
            return;
        visit[i][j] = true;
        dfs(grid, visit, i + 1, j);
        dfs(grid, visit, i, j + 1);
        dfs(grid, visit, i - 1, j);
        dfs(grid, visit, i, j - 1);
    }

private:
    int res = 0;
};