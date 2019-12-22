class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        if (col == 0) return 0;
        vector<vector<int>> visited;
        for (int i = 0; i < row; ++i) {
            vector<int> temp(col, 0);
            visited.push_back(temp);
        }
        int num = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '0' || visited[i][j] == 1) continue;
                ++num;
                dfs(grid, visited, i, j);
            }
        }
        return num;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j) {
        int row = grid.size();
        int col = grid[0].size();
        if (i < 0 || i >= row || j < 0 || j >= col || visited[i][j] == 1 || grid[i][j] == '0') return;
        visited[i][j] = 1;
        dfs(grid, visited, i+1, j);
        dfs(grid, visited, i-1, j);
        dfs(grid, visited, i, j-1);
        dfs(grid, visited, i, j+1);
    }
};