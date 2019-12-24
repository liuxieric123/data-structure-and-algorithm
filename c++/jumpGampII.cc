class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if (size == 0 || size == 1) return 0;
        int states[size];
        for (int i = 0; i < size; ++i) {
            states[i] = INT_MAX;
        }
        states[0] = 0;
        int pos = 0;
        for (int i = 0; i < size; ++i) {
            int cur = i + nums[i];
            if (cur > pos) {
                for (int j = pos+1; j <= cur; ++j) {
                    states[j] = states[i] + 1;
                    if (j == size-1) return states[size-1];
                }
                pos = cur;
            }
        }
        return states[size-1];
    }
};