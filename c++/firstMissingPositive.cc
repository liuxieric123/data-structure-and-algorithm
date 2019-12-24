class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 1;
        int p = 0;
        while(p < size) {
            int temp = nums[p];
            if (nums[p] > 0 && nums[p] <= size && nums[temp-1] != temp){
                nums[p] = nums[temp-1];
                nums[temp-1] = temp;
            } else ++p;
        }
        int i =0;
        for (; i < size; ++i) {
            if (nums[i] != i+1)
                break;
        }
        return i+1;
    }
};