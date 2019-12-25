class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size < 2) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        vector<int> ans = intervals[0];
        for (int i = 1; i < size; ++i) {
            if (intervals[i][0] > ans[1]) {
                ret.push_back(ans);
                ans = intervals[i];
            } else if (intervals[i][1] > ans[1]) {
                ans[1] = intervals[i][1];
            } else continue;
        }
        ret.push_back(ans);
        return ret;
    }

    vector<vector<int>> merge1(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size < 2) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        ret.push_back(intervals[0]);
        for (int i = 1; i < size; ++i) {
            int n = ret.size() - 1;
            if (intervals[i][0] > ret[n][1]) {
                ret.push_back(intervals[i]);
            } else if (intervals[i][1] > ret[n][1]) {
                ret[n][1] = intervals[i][1];
            } else continue;
        }
        return ret;
    }
};