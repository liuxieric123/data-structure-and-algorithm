class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        vector<int> ret;
        int max_ret = 0;
        if (size >= 2) {
            ret.push_back(nums[0]);
            ret.push_back(nums[1]);
            max_ret = max(ret[0], ret[1]);
        }
        if (size >= 3) {
            max_ret = max(nums[1], nums[0] + nums[2]);
            ret.push_back(nums[0] + nums[2]);
        }
        for (int i = 3; i < size; ++i) {
            ret.push_back(max(nums[i] + ret[i-3], nums[i] + ret[i-2]));
            max_ret = max(max_ret, ret[i]);
        }
        return max_ret;
    }
};