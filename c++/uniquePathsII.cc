class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        unsigned states[m][n];
        bool initialize_obstacle = false;
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 1)
                initialize_obstacle = true;
            if (initialize_obstacle) {
                states[i][0] = 0;
                continue;
            }
            states[i][0] = 1;
        }
        initialize_obstacle = false;
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[0][j] == 1)
                initialize_obstacle = true;
            if (initialize_obstacle) {
                states[0][j] = 0;
                continue;
            }
            states[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    states[i][j] = 0;
                } else {
                    states[i][j] = states[i-1][j] + states[i][j-1];
                }
            }
        }
        return states[m-1][n-1];
    }
};