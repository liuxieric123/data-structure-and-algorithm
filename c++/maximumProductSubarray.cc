class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int ret = INT_MIN;
        for (int i = 0; i < size; ++i) {
            ret = max(ret, nums[i]);
            int tmp = nums[i];
            for (int j = i+1; j < size; ++j) {
                tmp *= nums[j];
                ret = max(ret, tmp);
            }
        }
        return ret;
    }

    int maxProduct1(vector<int>& nums) {
        int curMax = nums[0], curMin = nums[0], maxRet = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int tmp;
            tmp = max(nums[i], max(curMax*nums[i], curMin*nums[i]));
            curMin = min(nums[i], min(curMin*nums[i], curMax*nums[i]));
            curMax = tmp;
            maxRet = max(curMax, maxRet);
        }
        return maxRet;
    }
};