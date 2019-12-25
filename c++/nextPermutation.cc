class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return;
        int pointer1 = size - 2;
        while(pointer1 >= 0) {
            if (nums[pointer1] >= nums[pointer1+1])
                --pointer1;
            else break;
        }
        int pointer2 = size - 1;
        while(pointer1 >= 0 && pointer1 < pointer2) {
            if (nums[pointer1] < nums[pointer2]) break;
            else --pointer2;
        }
        if (pointer1 >= 0) swap(nums[pointer1], nums[pointer2]);
        reverse(nums.begin()+pointer1+1, nums.end());
        return;
    }
};