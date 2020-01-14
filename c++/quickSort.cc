#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
using std::swap;
using std::cout;
using std::endl;

void partition(vector<int> & nums, int start, int end) {
    if (start < end) {
        int pivot = nums[end];
        int j = start;
        for (int i = start; i < end; ++i) {
            if (nums[i] < pivot) {
                swap(nums[j], nums[i]);
                ++j;
            }
        }
        swap(nums[j], nums[end]);
        partition(nums, start, j - 1);
        partition(nums, j + 1, end);
    }
}

void sort(vector<int> & nums) {
    int size = nums.size();
    if (size < 2) return;
    partition(nums, 0, size - 1);
    return;
}

int main () {
    vector<int> nums{2, 3, 1, 5, 2, 9, 0};
    sort(nums);
    for (auto i : nums) {
        cout << i << endl;
    }
    return 0;
}