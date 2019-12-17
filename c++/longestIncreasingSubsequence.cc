class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int states[size];
        int len = 0;
        for (int i = 0; i < size; ++i) {
            states[i] = 1;
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    states[i] = max(states[i], states[j] + 1);
                }
            }
            len = max(len, states[i]);
        }
        return len;
    }

    int lengthOfLIS1(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> states;
        states.push_back(INT_MAX);
        int len = 1;
        for (auto i : nums) {
            int index = binarySearch(states, len, i);
            states[index] = i;
            if ((index+1) == len) {
                states.push_back(INT_MAX);
                ++len;
            }
        }
        return states.size() - 1;
    }
private:
    // 找到的一定是大于等于目标值的
    int binarySearch(vector<int> & nums, int len, int target) {
        int low = 0, high = len - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
    
};