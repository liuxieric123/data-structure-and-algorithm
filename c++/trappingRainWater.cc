class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        if (size < 3) return 0;
        vector<int> left;
        left.push_back(0);
        for (int i = 1; i < size; ++i) {
            left.push_back(max(left[i-1], height[i-1]));
        }
        int right = 0;
        int count = 0;
        for (int i = size - 1; i >= 0; --i) {
            int ans = min(right,left[i]) - height[i];
            if (ans > 0) count += ans;
            right = max(right, height[i]); 
        }
        return count;
    }
};