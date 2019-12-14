class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        int stole_one[size+1];
        int not_stole_one[size+1];
        stole_one[0] = 0;
        stole_one[1] = nums[0];
        stole_one[2] = nums[1];
        not_stole_one[0] = 0;
        not_stole_one[1] = 0;
        not_stole_one[2] = nums[1];
        int maxRet = max(nums[0], nums[1]);
        for (int i = 3; i < size+1; ++i) {
            if (i == size) 
                stole_one[i] = 0;
            else 
                stole_one[i] = max(nums[i-1]+stole_one[i-2] , nums[i-1]+stole_one[i-3]);
            not_stole_one[i] = max(nums[i-1]+not_stole_one[i-2] , nums[i-1]+not_stole_one[i-3]);
            maxRet = max(maxRet, max(stole_one[i], not_stole_one[i]));
        }
        return maxRet;
    }
};