class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int gap = INT_MAX;
        for (int i = size - 1; i >= 2; --i) {
            int newTarget = target - nums[i];
            int j = 0, k = i - 1;
            while(j < k) {
                int sum = nums[j] + nums[k];
                int ans = sum - newTarget;
                if (abs(ans) < abs(gap))
                    gap = ans;
                if (sum < newTarget) {
                    ++j;
                    continue;
                } else if (sum > newTarget) {
                    --k;
                    continue;
                } else {
                    return target;
                }
            }
        }
        return target + gap;
    }
};