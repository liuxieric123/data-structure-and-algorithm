#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::swap;
using std::cout;
using std::endl;

void sort(vector<int> & nums) {
    int size = nums.size();
    if (size < 2) return;
    for (int i = 1; i < size; ++i) {
        int j = i;
        for (; j > 0 && nums[j] < nums[j-1]; --j) {
            swap(nums[j], nums[j-1]);
        }
    }
    return;
}

int main () {
    vector<int> nums{4,1,9,2,3,0};
    sort(nums);
    for (auto i : nums) {
        cout << i << endl;
    }
    return 0;
}