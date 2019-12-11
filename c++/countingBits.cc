class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> vec;
        vec.push_back(0);
        for (int i = 1; i <= num; ++i) {
            vec.push_back(vec[i&(i-1)]+1);
        }
        return vec;
    }
};