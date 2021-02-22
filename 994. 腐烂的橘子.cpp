class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return -1;
        int minute = 0;
        int goodOrange = 0;
        queue<Point> qu;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2)
                    qu.push(move(Point(i, j)));
                else if(grid[i][j] == 1)
                    goodOrange++;
            }
        }

        while(!qu.empty() && goodOrange > 0) {
            int size = qu.size();
            while(size--) {
                Point p = qu.front();
                qu.pop();

                if(p.x - 1 >= 0 && grid[p.x - 1][p.y] == 1) {
                    grid[p.x - 1][p.y] = 2;
                    qu.push(move(Point(p.x - 1, p.y)));
                    goodOrange--;
                }
                if(p.x + 1 <= grid.size() - 1 && grid[p.x + 1][p.y] == 1) {
                    grid[p.x + 1][p.y] = 2;
                    qu.push(move(Point(p.x + 1, p.y)));
                    goodOrange--;
                }
                if(p.y - 1 >= 0 && grid[p.x][p.y - 1] == 1) {
                    grid[p.x][p.y - 1] = 2;
                    qu.push(move(Point(p.x, p.y - 1)));
                    goodOrange--;
                }
                if(p.y + 1 <= grid[0].size() - 1 && grid[p.x][p.y + 1] == 1) {
                    grid[p.x][p.y + 1] = 2;
                    qu.push(move(Point(p.x, p.y + 1)));
                    goodOrange--;
                }
            }
            minute++;
        }

        return goodOrange == 0 ? minute : -1;
    }

private:
    struct Point {
        int x;
        int y;
        Point(int _x, int _y) : x(_x), y(_y) {}
    };
};