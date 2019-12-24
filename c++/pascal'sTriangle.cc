class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if (numRows == 0) return ret;
        ret.push_back(vector<int>{1});
        if (numRows == 1) return ret;
        for (int i = 1; i < numRows; ++i) {
            vector<int> temp{1};
            for (int j = 0; j < ret[i-1].size()-1;++j) {
                temp.push_back(ret[i-1][j]+ret[i-1][j+1]);
            }
            temp.push_back(1);
            ret.push_back(temp);
        }
        return ret;
    }
};