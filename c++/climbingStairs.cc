class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return 1;
        return climbStairs(n-1) + climbStairs(n-2);
    }

    int climbStairs1(int n) {
        if (n < 2) return 1;
        int one = 1;
        int two = 2;
        for (int i = 3; i < n + 1; ++i) {
            int tmp = two;
            two = one + two;
            one = tmp;
        }
        return two;
    }

};