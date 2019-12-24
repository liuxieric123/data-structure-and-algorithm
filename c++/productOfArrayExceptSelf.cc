class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return {};
        vector<int> left;
        vector<int> right;
        
        left.push_back(nums[0]);
        right.push_back(nums.back());
        for (int i = 1; i < size; ++i) {
            left.push_back(left[i-1]*nums[i]);
            right.push_back(right[i-1]*nums[size-i-1]);
        }
        reverse(right.begin(), right.end());
        vector<int> ret;
        for (int i = 0; i < size; ++i) {
            int l = i == 0 ? 1 : left[i-1];
            int r = i == size - 1 ? 1 : right[i+1]; 
            ret.push_back(l*r);
        }
        return ret;
    }
};