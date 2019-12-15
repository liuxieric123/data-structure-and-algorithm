class Solution {
public:
    bool judgeSquareSum(int c) {
        int end = sqrt(c);
        int i = 0;
        while(i <= end){
            if (i*i > c - end*end){
                --end;
            } else if (i*i < c - end*end) {
                ++i;
            } else {
                return true;
            }
        }
        return false;
    }
};