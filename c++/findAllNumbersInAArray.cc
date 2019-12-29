class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        if (size == 0 || size == 1) return {};
        int pos = 0;
        while(pos < size) {
            if (nums[pos] == pos+1 || nums[nums[pos]-1] == nums[pos]) {
                   ++pos;
                   continue;
            }
            swap(nums[pos], nums[nums[pos]-1]);
        }
        vector<int> ret;
        for (int i = 0; i < size; ++i) {
            if (nums[i] != i+1)
                ret.push_back(i+1);
        }
        return ret;
    }
};