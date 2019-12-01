#include <vector>

using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int len = matrix[0].size();
        for (int i = 0; i < matrix.size(); ++i) {
            if (target > matrix[i][len-1]) continue;
            else if (target < matrix[i][len - 1]) {
                return binarySearch(matrix[i], target) != -1; 
            } else {
                return true;
            }
        }
        return false;
    }

    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int index = vertical_search(matrix, target);
        if (index >= matrix.size()) return false;
        return binarySearch(matrix[index], target) != -1;
    }
    
    int binarySearch(vector<int> & nums, int target) {
        if (nums.size() == 0) return -1;
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        int mid = len / 2;
        while (left <= right) {
            if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                return mid;
            }
            mid = left + (right - left) / 2;
        }
        return -1;
    }
    

    int vertical_search(vector<vector<int>> & matrix, int target) {
        int len = matrix.size();
        int finalIndex = matrix[0].size() - 1;
        int up = 0;
        int down = len - 1;
        while (up <= down) {
            int mid = up + (down - up) / 2;
            if (matrix[mid][finalIndex] < target) {
                up = mid + 1;
            } else if (matrix[mid][finalIndex] > target) {
                down = mid - 1;
            } else {
                return mid;
            }
        }
        return up;
    }
};