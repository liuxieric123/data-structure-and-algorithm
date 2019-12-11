class Solution {
public:
    int numSquares(int n) {
        vector<int> vec;
        vec.push_back(0);
        for (int i = 1; i <= n; ++i) {
            vec.push_back(i);
            for (int j = 1; j * j <= i; ++j) {
                vec[i] = min(vec[i], vec[i-j*j] + 1);
            }
        }
        return vec[n];
    }
};