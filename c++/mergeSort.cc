#include <vector>
#include <iostream>
#include <limits>

using std::vector;
using std::cout;
using std::endl;
using std::numeric_limits;

void merge(vector<int> &nums, int front, int mid, int end) {
    
    vector<int> left(nums.begin() + front, nums.begin() + mid + 1);
    vector<int> right(nums.begin() + mid + 1, nums.begin() + end + 1);
    left.insert(left.end(), numeric_limits<int>::max());
    right.insert(right.end(), numeric_limits<int>::max());
    int idxLeft = 0, idxRight = 0;
    for (int i = front; i <= end; ++i) {
        if (left[idxLeft] < right[idxRight]) {
            nums[i] = left[idxLeft];
            ++idxLeft;
        } else {
            nums[i] = right[idxRight];
            ++idxRight;
        }
    }
}

void sort(vector<int> & nums, int front, int end) {
    if (front >= end) return;
    int mid = front + (end - front) / 2;
    sort(nums, front, mid);
    sort(nums, mid+1, end);
    merge(nums, front, mid, end);
    return;
}

int main () {
    vector<int> nums{6, 5, 1, 3, 2, 4, 8, 7};
    sort(nums, 0, nums.size()-1);
    for (auto i : nums) {
        cout << i << endl;
    }
    return 0;
}