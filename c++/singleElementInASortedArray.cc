class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int size = nums.size();
        int high = size - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (mid % 2 == 0) {
                if (mid + 1 < size && nums[mid] == nums[mid + 1]) low = mid + 2;
                else if (mid > 0 && nums[mid] == nums[mid - 1]) high = mid - 2;
                else return nums[mid];
            } else {
                if (mid + 1 < size && nums[mid] == nums[mid + 1]) high = mid - 1;
                else if (mid > 0 && nums[mid] == nums[mid - 1]) low = mid + 1;
                else return nums[mid];
            }
        }
        return low;
    }
};