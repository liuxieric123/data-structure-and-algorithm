class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] == nums[j]) return nums[i];
            }
        }
        return -1;
    }

    int findDuplicate1(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (auto i : nums) {
                if (i <= mid) ++count;
            }
            if (count > mid) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};