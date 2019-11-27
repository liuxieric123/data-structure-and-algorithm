#include <vector>
#include <iostream>

using std::vector;

class Solution {
    public:
        int singleNum (vector<int> & nums) {
            int ret = 0;
            for (auto & i: nums) {
                ret ^= i;
            }
            return ret;
        }
};

int main() {
    vector<int> test{1,2,3,4,4,3,2};
    int result;
    Solution s;
    result = s.singleNum(test);
    std::cout << result << std::endl;
}