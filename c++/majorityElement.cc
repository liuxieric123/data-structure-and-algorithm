#include <vector>

using std::vector;

class Solution {

    int majorityElement(vector<int> & nums) {
        int num = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (num == nums[i]) ++count;
            else if (count != 0) --count;
            else {
                num = nums[i];
                count = 1;
            }
        }
        return num;
    }
};