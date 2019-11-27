#include <vector>
#include <iostream>

using std::vector;

class Solution {
    public:
        vector<int>  twoSumII(vector<int> & numbers, int target) {
            int i = 0;
            int j = numbers.size() - 1;
            while(i != j) {
                if (numbers[i] + numbers[j] < target) {
                    ++i;
                } else if (numbers[i] + numbers[j] > target) {
                    --j;
                } else {
                    return vector<int>{i+1, j+1};
                }
            }
            return vector<int>{-1, -1};
        }
};

int main () {
    vector<int> test{2,7,11,15};
    vector<int> result;
    Solution s;
    result = s.twoSumII(test, 18);
    for (auto i : result) {
        std::cout << i << std::endl;
    }
}