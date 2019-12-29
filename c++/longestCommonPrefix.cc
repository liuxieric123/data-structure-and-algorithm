class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (size == 0) return "";
        string ret = strs[0];
        for (int i = 1; i < size; ++i) {
            if (strs[i].size() < ret.size()) {
                ret.erase(ret.begin()+strs[i].size(), ret.end());
            }
            for (int j = ret.size()-1; j >= 0; --j) {
                if (strs[i][j] && strs[i][j] != ret[j]) {
                    ret.erase(ret.begin()+j, ret.end());
                }
            }
        }
        return ret;
    }
};