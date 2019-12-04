#include <vector>
#include <algorithm>

using std::max;
using std::min;
using std::vector;

class Solution {
public:
    int maxArea(vector<int>& height) {
       int area = 0;
       int i = 0, j = height.size() - 1;
       while (i < j) {
           area = max(area, min(height[i], height[j])*(j-i));
           if (height[i] < height[j]) ++i;
           else --j;
       }
       return area;
    }
};