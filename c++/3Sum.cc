class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int size = nums.size();
        for (int k = size - 1; k >= 2; --k) {
            if (nums[k] < 0) break;
            int target = -nums[k], i = 0, j = k - 1;
            while(i < j) {
                if (nums[i] + nums[j] == target) {
                    vector<int> tmp{nums[i], nums[j], nums[k]};
                    ret.push_back(tmp);
                    while(i < j && nums[i+1] == nums[i]) ++i;
                    while(i < j && nums[j-1] == nums[j]) --j;
                    ++i;
                    --j;
                } else if (nums[i] + nums[j] < target) {
                    while(i < j && nums[i+1] == nums[i]) ++i;
                    ++i;
                } else {
                    while(i < j && nums[j-1] == nums[j]) --j;
                    --j;
                }

            }
            while(k >= 2 && nums[k-1] == nums[k]) --k;
        }
        return ret;
    }
};