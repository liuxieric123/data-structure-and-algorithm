class Solution {
    int getSum(int a, int b) {
        return b == 0 ? a :
        getSum((static_cast<unsigned>(a)^static_cast<unsigned>(b)), 
        (static_cast<unsigned>(a)&static_cast<unsigned>(b)) << 1);
    }
};