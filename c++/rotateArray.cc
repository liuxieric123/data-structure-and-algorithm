class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 0 || size == 1) return;
        k = k % size;
        int temp;
        for (int i = 0; i < k; ++i) {
            temp = nums.back();
            nums.pop_back();
            nums.insert(nums.begin(), temp);
        }
        return;
    }

    void rotate1(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 0 || size == 1) return;
        k = k % size;
        vector<int> temp(nums.begin()+(size-k), nums.end());
        nums.erase(nums.begin()+(size-k), nums.end());
        nums.insert(nums.begin(), temp.begin(), temp.end());
        return;
    }

    void rotate3(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 0 || size == 1 || k % size == 0) return;
        k = k % size;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        return;
    }
};