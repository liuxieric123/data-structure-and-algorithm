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
};