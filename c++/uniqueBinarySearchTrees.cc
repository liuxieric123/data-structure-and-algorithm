class Solution {
public:
    int numTrees(int n) {
        vector<int> vec;
        if (n == 0) return 0;
        vec.push_back(1);
        if (n == 1) return 1;
        vec.push_back(1);
        if (n == 2) return 2;
        vec.push_back(2);
        for (int i = 3; i <= n; ++i) {
            int sum = 0;
            for (int j = i - 1; j > (i-1)/2; --j) {
                sum += (2*vec[j]*vec[i-j-1]);
            }
            if (i%2 == 1)  sum += (vec[(i-1)/2]*vec[(i-1)/2]);
            vec.push_back(sum);
        }
        return vec[n];
    }
};