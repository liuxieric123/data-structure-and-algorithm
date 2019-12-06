class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n != 0) {
            ++count;
            n &= n-1;
        }
        return count;
    }

    int hammingWeight1(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            if (n & 1 == 1) ++count;
            n >>= 1; 
        }
        return count;
    }
};