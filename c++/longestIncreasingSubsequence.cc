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
};