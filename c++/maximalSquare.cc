class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        int states[row][col];
        int area = 0;
        for (int i = 0; i < col; ++i) {
            states[0][i] = matrix[0][i] == '1' ? 1 : 0;            
            area = max(area, states[0][i]);

        }
        for (int i = 0; i < row; ++i) {
            states[i][0] = matrix[i][0] == '1' ? 1 : 0;
            area = max(area, states[i][0]);
        }
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (states[i-1][j-1] == 0 || matrix[i][j] == '0')
                    states[i][j] = matrix[i][j] == '1' ? 1 : 0;
                else {
                    states[i][j] = 1;
                    for (int z = 1; z <= sqrt(states[i-1][j-1]); ++z) {
                        if (matrix[i][j-z] == '0' || matrix[i-z][j] == '0') {
                            break;
                        }
                        states[i][j] = (z+1)*(z+1);
                    }
                }
                area = max(area, states[i][j]);
            }
        }
        return area;
    }
};