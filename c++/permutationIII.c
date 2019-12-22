class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return vector<vector<int>>{};
        set<int> set_num;
        map<int, int> map_count;
        for (int i = 0; i < size; ++i) {
            set_num.insert(nums[i]);
            if (map_count.find(nums[i]) != map_count.end()) ++map_count[nums[i]];
            else map_count[nums[i]] = 1;
        }
        vector<vector<int>> ret;
        vector<int> temp;
        dfs(ret, temp, set_num, map_count, size);
        return ret;
    }

    void dfs(vector<vector<int>> & ret, vector<int> & temp, 
        set<int> &set_num, map<int, int> &num_count, int size) {
        if (temp.size() == size) {
            ret.push_back(temp);
            return;
        }
        for (auto i : set_num) {
            if (num_count[i] != 0) {
                temp.push_back(i);
                --num_count[i];
                dfs(ret, temp, set_num, num_count, size);
                ++num_count[i];
                temp.erase(temp.end()-1);
            }
        }
    }
};