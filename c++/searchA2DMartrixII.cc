#include <vector>


using std::vector;
class Solution {
    bool searchA2DMartirxII(vector<vector<int>> & matrix, int target) {
        if (matrix.empty() || matrix.begin() -> empty()) return false;
        int m = matrix.size();
        int n = matrix.begin() -> size();
        int i = 0;
        int j = n - 1;
        while(i < m && j >= 0) {
            if (target > matrix[i][j]) ++i;
            else if (target < matrix[i][j]) --j;
            else return true;
        }
        return false;
    }
};