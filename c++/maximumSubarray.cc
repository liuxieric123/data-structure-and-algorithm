#include <vector>
#include <algorithm>
#include <climits>

using std::vector;
using std::max;

class Solution {
    int maxSubArray(vector<int> & nums) {
        int result = INT_MIN;
        int sum = 0;
        for (auto i : nums) {
            sum += i;
            result = max(result, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return result;
    }
};