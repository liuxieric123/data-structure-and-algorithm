class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        int low = 1;
        int high = x;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (x / mid > mid) low = mid + 1;
            else if (x / mid < mid) high = mid - 1;
            else return mid;
        }
        return high;
    }

     int mySqrt1(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        double ret = 1;
        while(abs(ret * ret - x) >= 1) {
            ret = (ret + x / ret) / 2;
        }
        return ret;
    }

    int mySqrt2(int x) {
        if (x == 0) return 0;
        int low = 1, high = x;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if (mid < int(sqrt(x))) low = mid + 1;
            else high = mid;
        }
        return low;
    }

    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        int low = 1, high = x;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if (x / mid >= mid) low = mid + 1;
            else high = mid;
        }
        return low-1;
    }
};