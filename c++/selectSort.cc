#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::swap;

void sort(vector<int> &nums) {
    for (auto it1 = nums.begin(); it1 != nums.end(); ++it1) {
        auto min = it1;
        for (auto it2 = it1; it2 != nums.end(); ++it2) {
            if (*it2 < *min) min = it2;
        }
        swap(*it1, *min);
    }
    return;
}

int main() {
    vector<int> nums{1,3,4,2,6,2,3};
    sort(nums);
    for (auto i : nums) {
        cout << i << endl;
    }
    return 0;
}