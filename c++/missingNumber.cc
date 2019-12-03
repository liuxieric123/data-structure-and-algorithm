#include <vector>

using std::vector;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int totalSum = size * (size + 1) / 2;
        for (auto i : nums) {
            totalSum -= i;
        }
        return totalSum;
    }

    int missingNumber(vector<int> & nums) {
        int result = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            result = result ^ i ^ nums[i];
        }
        return result;
    }
};