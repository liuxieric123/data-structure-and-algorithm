#include <vector>
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
using std::swap;
using std::vector;

void sort(vector<int> & nums) {
    int size = nums.size();
    if (size == 0) return;
    for (int i = size - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j+1] < nums[j]) {
                swap(nums[j+1], nums[j]);
            }
        }
    }
    return;
}

int main () {
    vector<int> nums = {1,3,4,2,6,1};
    sort(nums);
    for (auto i : nums) {
        cout << i << endl;
    }
    return 0;
}