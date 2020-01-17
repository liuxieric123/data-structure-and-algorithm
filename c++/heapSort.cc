#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::swap;
using std::cout;
using std::endl;

void heapify(vector<int> & nums, int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while(son < end) {
        if (son + 1 < end && nums[son+1] > nums[son]) {
            ++son;
        }
        if (nums[dad] > nums[son]) return;
        else {
            swap(nums[dad], nums[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void sort(vector<int> & nums) {
    int size = nums.size();
    if (size < 2) return;
    for (int i = (size-2) / 2; i >= 0; --i) {
        heapify(nums, i, size);
    }
    for (int i = 0; i < size; ++i) {
        swap(nums[0], nums[size - i - 1]);
        heapify(nums, 0, size - i - 1);
    }
    return;
}

int main () {
    vector<int> nums{2, 3, 5, 10, 7, 9};
    sort(nums);
    for (auto i : nums) {
        cout << i << endl;
    }
    return 0;
}

