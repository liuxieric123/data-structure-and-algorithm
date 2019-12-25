class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0) return;
        int col = matrix[0].size();
        if (col == 0) return;
        for (int i = 0; i < row; ++i) {
            for (int j = i + 1; j < col; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col/2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][col-j-1];
                matrix[i][col-j-1] = temp;
            }
        }
        return;
    }
};