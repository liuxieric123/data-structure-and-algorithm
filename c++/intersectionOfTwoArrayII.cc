class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map_count;
        vector<int> ret;
        for (auto i : nums1) {
            if (map_count.find(i) != map_count.end()) map_count[i] += 1;
            else map_count.insert(pair<int, int>(i, 1));
        }
        for (auto i : nums2) {
            if (map_count.find(i) != map_count.end()) {
                if (map_count[i] != 0) {
                    ret.push_back(i);
                    map_count[i] -= 1;
                }
            }
        }
        return ret;
    }

     vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ret;
        int pointer_1 = 0;
        int pointer_2 = 0;
        int size_1 = nums1.size();
        int size_2 = nums2.size();
        while(pointer_1 < size_1 && pointer_2 < size_2) {
            if (nums1[pointer_1] == nums2[pointer_2]) {
                ret.push_back(nums1[pointer_1]);
                ++pointer_1;
                ++pointer_2;
            } else if (nums1[pointer_1] < nums2[pointer_2]) {
                ++pointer_1;
            } else {
                ++pointer_2;
            }
        }
        return ret;
    }
};