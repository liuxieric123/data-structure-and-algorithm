class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[mid+1]) low = mid + 1;
            else high = mid;
        }
        return low;
    }

    int findPeakElement1(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size - 1; ++i) {
            if (nums[i] > nums[i+1]) return i;
        }
        return size - 1;
    }
};