#include <stdlib.h>

class Solution {
    double pow(double x, int n) {
        long multi = abs(long(n));
        double result = 1;
        while(multi != 0) {
            if ((multi & 1) == 1) result *= x;
            x *= x;
            multi >>= 1;
        } 
        return result;
    }
};