class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0) return false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                if(word[0] == board[i][j] && dfs(board, visited, word, i, j, 0)) 
                    return true;
        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int i, int j, int index) {
        if(index == word.size()) return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index] || visited[i][j])
            return false;
        visited[i][j] = true;

        bool flag = dfs(board, visited, word, i - 1, j, index + 1) ||
        dfs(board, visited, word, i + 1, j, index + 1) ||
        dfs(board, visited, word, i, j - 1, index + 1) ||
        dfs(board, visited, word, i, j + 1, index + 1);

        visited[i][j] = false;

        return flag;
    }
};