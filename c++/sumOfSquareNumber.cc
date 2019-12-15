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

     bool judgeSquareSum1(int c) {
        int end = sqrt(c);
        set<int> set_tmp;
        for (int i = 0; i <= end; ++i) {
            set_tmp.insert(i*i);
            if (set_tmp.find(c-i*i) != set_tmp.end())
                return true;
        }
        return false;
    }
};