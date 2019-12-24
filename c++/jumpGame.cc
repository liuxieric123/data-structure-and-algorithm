class Solution {
public:
    bool canJump(vector<int>& nums) {
        int able = 0;
        int size = nums.size();
        for (int i = 0; i <= able; ++i) {
            able = max(able, i+nums[i]);
            if (able >= size - 1) return true;
        }
        return false;
    }
};