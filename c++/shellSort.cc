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
    for (int gap = (size >> 1); gap >= 1; gap >>= 1) {
        for (int i = gap; i < size; ++i) {
            for (int j = i; j > 0; j -= gap) {
                if (nums[j] < nums[j-gap])
                    swap(nums[j], nums[j-gap]);
            }
        }
    }
    return;
}

int main () {
    vector<int> nums{2, 5, 6, 1, 4, 2, 9};
    sort(nums);
    for (auto i : nums) {
        cout << i << endl;
    }
    return 0;
}