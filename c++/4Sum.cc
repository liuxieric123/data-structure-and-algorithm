class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (int p = nums.size()-1; p >= 3; --p) {
            if (nums[p]*4 < target) break;
            for (int k = p - 1; k >= 2; --k) {
                if (nums[p] + nums[k]*3 < target) break;
                int i = 0, j = k - 1, newTarget = target - nums[p] - nums[k];
                while (i < j) {
                    if (nums[i] + nums[j] == newTarget) {
                        ret.push_back(vector<int>{nums[i], nums[j], nums[k], nums[p]});
                        while(i < j && nums[i + 1] == nums[i]) ++i;
                        while(i < j && nums[j - 1] == nums[j]) --j;
                        ++i;
                        --j;
                    } else if (nums[i] + nums[j] < newTarget) {
                        while(i < j && nums[i + 1] == nums[i]) ++i;
                        ++i;
                    } else {
                        while(i < j && nums[j - 1] == nums[j]) --j;
                        --j;
                    }
                }
                while( k >= 2 && nums[k - 1] == nums[k]) --k;
            }
            while(p >= 3 && nums[p - 1] == nums[p]) --p;
        }
        return ret;
    }
};