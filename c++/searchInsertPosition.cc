#include <vector>

using std::vector;

class Solution {
    public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        int mid = len / 2;
        while(left <= right) {
            if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                return mid;
            }
            mid = left + (right - left) / 2;
        }
        return left;
    }
    
    int searchInsert1(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        int low = 0, high = nums.size();
        while(low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};