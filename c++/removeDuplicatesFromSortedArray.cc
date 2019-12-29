class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        auto pointer = nums.begin();
        while(pointer != nums.end()) {
            if (pointer + 1 != nums.end()) {
                if (*pointer == *(pointer+1)){
                    nums.erase(pointer+1);
                    --size;
                } else {
                    ++pointer;
                }
            } else break;
        }
        return size;
    }

    int removeDuplicates1(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int p = 1;
        for (int q = 1; q < size; ++q) {
            if (nums[q] != nums[q-1]) {
                nums[p++] = nums[q];
            }
        }
        return p;
    }
};