class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        int f = 0;
        int s = 0;
        while(f != size) {
            if (nums[f] != 0) {
                nums[s] = nums[f];
                ++f;
                ++s;
            } else {
                ++f;
            }
        }
        for (int i = s; i < size; ++i) {
            nums[i] = 0;
        }
        return;
    }

     void moveZeroes1(vector<int>& nums) {
        int size = nums.size();
        int f = 0;
        int s = 0;
        while(f != size) {
            if (nums[f] != 0) {
                swap(nums[f], nums[s]);
                ++f;
                ++s;
            } else {
                ++f;
            }
        }
        return;
    }
};