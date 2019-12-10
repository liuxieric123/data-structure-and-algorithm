class Solution {
public:
    int fib(int N) {
        vector<int> vec;
        vec.push_back(0);
        vec.push_back(1);
        for (int i = 2; i <= N; ++i) {
            vec.push_back(vec[i-1] + vec[i-2]);
        }
        return vec[N];
    }
};