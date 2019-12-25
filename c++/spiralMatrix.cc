class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0) return {};
        int col = matrix[0].size();
        if (col == 0) return {};
        int top = 0, bottom = row - 1, left = 0, right = col - 1;
        vector<int> ret;
        while(true) {
            if (top > bottom || left > right) break;
            else {
                for (int i = left; i <= right; ++i) {
                    ret.push_back(matrix[top][i]);
                }
                ++top;
            }
            if (top > bottom || left > right) break;
            else {
                for (int i = top; i <= bottom; ++i) {
                    ret.push_back(matrix[i][right]);   
                }
                --right;
            }
            if (top > bottom || left > right) break;
            else {
                for (int i = right; i >= left; --i) {
                    ret.push_back(matrix[bottom][i]);
                }
                --bottom;
            } 
            if (top > bottom || left > right) break;
            else {
                for (int i = bottom; i >= top; --i) {
                    ret.push_back(matrix[i][left]);
                }
                ++left;
            }
        }
        return ret;
    }
};