class Solution {
public:
    int uniquePaths(int m, int n) {
        int states[m][n];
        for (int i = 0; i < m; ++i) 
            states[i][0] = 1;
        for (int i = 0; i < n; ++i)
            states[0][i] = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                states[i][j] = states[i-1][j] + states[i][j-1];
            }
        }
        return states[m-1][n-1];
    }
};