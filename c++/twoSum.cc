#include <vector>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::unordered_map;
class Solution {
    public:
        vector<int> twoSum(vector<int> & nums, int target) {
            unordered_map<int, int> m;
            vector<int> result;
            for (int i = 0; i < nums.size(); ++i) {
                if (m.find(target - nums[i]) == m.end()) {
                    m[nums[i]] = i;
                } else {
                    result.push_back(m[target - nums[i]]);
                    result.push_back(i);
                    break;
                }

            }
            return result;
        }
};

int main () {
    vector<int> test{1,2,3,4,5,6};
    Solution s;
    vector<int> result = s.twoSum(test, 7);
    for (auto i : result) {
        std::cout << i << std::endl;
    }
}