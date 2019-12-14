class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int states[n];
        for (int i = 0; i < n; ++i) {
            if (i == 0) states[i] = grid[0][0];
            else states[i] = grid[0][i] + states[i-1];
        }
        for (int i = 1; i < m; ++i) {
            states[0] = states[0] + grid[i][0];
            for (int j = 1; j < n; ++j) {
                int top = states[j];
                int left = states[j-1];
                states[j] = min(top+grid[i][j], left+grid[i][j]);
            }
        }
        return states[n-1];
    }
};