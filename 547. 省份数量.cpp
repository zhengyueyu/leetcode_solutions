class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.empty() || isConnected[0].empty()) return 0;
        if(isConnected.size() != isConnected[0].size()) return 0;
        vector<bool> visited(isConnected.size(), false);
        int num = 0;
        for(int i = 0; i < isConnected.size(); i++)
            if(visited[i] == false) {
                dfs(isConnected, i, visited);
                num++;
            }
        return num;
    }

    void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited) {
        for(int k = 0; k < isConnected[0].size(); k++) {
            if(!visited[k] && isConnected[i][k]) {
                visited[k] = true;
                dfs(isConnected, k, visited);
            }
        }
    }
};