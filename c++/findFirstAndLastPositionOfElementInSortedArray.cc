class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int low = 0, high = size - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                int pointer = mid;
                vector<int> ret;
                while(pointer >= 0 && nums[pointer] == target) {
                    --pointer;
                }
                ret.push_back(pointer + 1);
                pointer = mid;
                while(pointer < size && nums[pointer] == target) {
                    ++pointer;
                }
                ret.push_back(pointer - 1);
                return ret;
            }
            else if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return vector<int>{-1, -1};
    }
};