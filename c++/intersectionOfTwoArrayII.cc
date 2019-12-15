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
};